#include <iostream>
#include <fstream>

#include "color.h"
#include "vec3.h"

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    std::ofstream img("output_image.raw", std::ios::out | std::ios::binary);
    //std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.0;
            auto pix_clr = color(r, g, b);

            //std::cout << ir << ' ' << ig << ' ' << ib << '\n';
            //img.put(ir).put(ig).put(ib);
            write_color(img, pix_clr);

        }
    }

    img.close();
    std::clog << "\rDone.                 \n";
    return 0;
}