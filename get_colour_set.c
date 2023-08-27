#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <png.h>

// Structure to store RGB color values
typedef struct {
    uint8_t r, g, b;
} RGBColor;

int main(int argc, char *argv[]) {
    printf("Executable name: %s\n", argv[0]); // Add this line
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.png output_colors.txt\n", argv[0]);
        return 1;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];

    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    // Initialize PNG structures
    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) {
        fclose(inputFile);
        fprintf(stderr, "Error initializing libpng\n");
        return 1;
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        fclose(inputFile);
        png_destroy_read_struct(&png, NULL, NULL);
        fprintf(stderr, "Error initializing libpng info\n");
        return 1;
    }

    if (setjmp(png_jmpbuf(png))) {
        fclose(inputFile);
        png_destroy_read_struct(&png, &info, NULL);
        fprintf(stderr, "Error reading PNG file\n");
        return 1;
    }

    png_init_io(png, inputFile);
    png_read_info(png, info);

    int width = png_get_image_width(png, info);
    int height = png_get_image_height(png, info);
    png_byte color_type = png_get_color_type(png, info);
    png_byte bit_depth = png_get_bit_depth(png, info);

    if (color_type != PNG_COLOR_TYPE_RGB || bit_depth != 8) {
        fclose(inputFile);
        png_destroy_read_struct(&png, &info, NULL);
        fprintf(stderr, "Input image must be in RGB format with 8-bit depth\n");
        return 1;
    }

    // Create a dynamic array to store unique colors as integers
    int maxColors = width * height;
    int numUniqueColors = 0;
    int uniqueColors[maxColors]; // Simplified for testing

    // Iterate through the image and count unique colors
    for (int y = 0; y < height; y++) {
        png_bytep row = png_malloc(png, sizeof(png_byte) * width * 3);
        png_read_row(png, row, NULL);

        for (int x = 0; x < width; x++) {
            RGBColor color;
            color.r = row[x * 3];
            color.g = row[x * 3 + 1];
            color.b = row[x * 3 + 2];

            int isUnique = 1;
            for (int i = 0; i < numUniqueColors; i++) {
                if (uniqueColors[i] == ((color.r << 16) | (color.g << 8) | color.b)) {
                    isUnique = 0;
                    break;
                }
            }

            if (isUnique) {
                numUniqueColors++;
                if (numUniqueColors >= maxColors) {
                    fprintf(stderr, "Too many unique colors\n");
                    fclose(inputFile);
                    png_destroy_read_struct(&png, &info, NULL);
                    return 1;
                }
                uniqueColors[numUniqueColors - 1] = ((color.r << 16) | (color.g << 8) | color.b);
            }
        }

        png_free(png, row);
    }

    printf("Number of unique colors: %d\n", numUniqueColors);

    // Clean up and close files
    fclose(inputFile);
    png_destroy_read_struct(&png, &info, NULL);

    return 0;
}
