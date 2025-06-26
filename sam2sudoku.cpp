#include <iostream>
#include <iomanip>

#include <fstream>
#include <vector>
#include <map>
#include <cstdarg>
#include <set>
#include <algorithm>
#include <cstring>
#include "sam2sudoku.h"




std::vector<int> get_candidates(int idx, int* zadanie, const std::vector<std::vector<int>>& Area, const std::map<int, std::vector<int>>& InverseMap, bool b_disp = true);

void RegisterArea(std::vector<std::vector<int> >& Areas, const std::vector<int>& NewArea) {
    Areas.push_back(NewArea);
}
void disp_elem(int e);

/*
        ... ... ...
        ... ... ...
        ... ... ...

        ... ... ...
        ... ... ...
        ... ... ...

... ... ... ... ... ... ...
... ... ... ... ... ... ...
... ... ... ... ... ... ...

... ... ...     ... ... ...
... ... ...     ... ... ...
... ... ...     ... ... ...

... ... ... ... ... ... ...
... ... ... ... ... ... ...
... ... ... ... ... ... ...

        ... ... ...
        ... ... ...
        ... ... ...

        ... ... ...
        ... ... ...
        ... ... ...

*/
const std::vector<int> expected_SAM2_sizes{ 9, 9, 9, 9, 9, 9, 21, 21, 21, 18, 18, 18, 21, 21, 21, 9, 9, 9, 9, 9, 9 };

bool read_SAM2_sudoku(std::ifstream& infile, int* zadanie) {
    return read_content_sudoku(infile, expected_SAM2_sizes, content_type::NUMBERS, true, 9, zadanie);
}

bool read_SAM2_sudoku_vec(std::ifstream& infile, std::vector<int> &zadanie) {
    return read_content_sudoku_vec(infile, expected_SAM2_sizes, content_type::NUMBERS, true, 9, zadanie);
}

void init_SAM2_areas(std::vector<std::vector<int>> &Areas_SAM2) {

    /*  Rows */
    RegisterArea(Areas_SAM2, std::vector<int>{ 0, 1, 2, 3, 4, 5, 6, 7, 8});
    RegisterArea(Areas_SAM2, std::vector<int>{ 9, 10, 11, 12, 13, 14, 15, 16, 17});
    RegisterArea(Areas_SAM2, std::vector<int>{18, 19, 20, 21, 22, 23, 24, 25, 26});

    RegisterArea(Areas_SAM2, std::vector<int>{27, 28, 29, 30, 31, 32, 33, 34, 35});
    RegisterArea(Areas_SAM2, std::vector<int>{36, 37, 38, 39, 40, 41, 42, 43, 44});
    RegisterArea(Areas_SAM2, std::vector<int>{45, 46, 47, 48, 49, 50, 51, 52, 53});

    RegisterArea(Areas_SAM2, std::vector<int>{54, 55, 56, 57, 58, 59, 60, 61, 62});
    RegisterArea(Areas_SAM2, std::vector<int>{60, 61, 62, 63, 64, 65, 66, 67, 68});
    RegisterArea(Areas_SAM2, std::vector<int>{66, 67, 68, 69, 70, 71, 72, 73, 74});

    RegisterArea(Areas_SAM2, std::vector<int>{75, 76, 77, 78, 79, 80, 81, 82, 83});
    RegisterArea(Areas_SAM2, std::vector<int>{81, 82, 83, 84, 85, 86, 87, 88, 89});
    RegisterArea(Areas_SAM2, std::vector<int>{87, 88, 89, 90, 91, 92, 93, 94, 95});

    RegisterArea(Areas_SAM2, std::vector<int>{ 96, 97, 98, 99, 100, 101, 102, 103, 104});
    RegisterArea(Areas_SAM2, std::vector<int>{102, 103, 104, 105, 106, 107, 108, 109, 110});
    RegisterArea(Areas_SAM2, std::vector<int>{108, 109, 110, 111, 112, 113, 114, 115, 116});

    RegisterArea(Areas_SAM2, std::vector<int>{117, 118, 119, 120, 121, 122, 123, 124, 125});
    RegisterArea(Areas_SAM2, std::vector<int>{126, 127, 128, 129, 130, 131, 132, 133, 134});

    RegisterArea(Areas_SAM2, std::vector<int>{135, 136, 137, 138, 139, 140, 141, 142, 143});
    RegisterArea(Areas_SAM2, std::vector<int>{144, 145, 146, 147, 148, 149, 150, 151, 152});

    RegisterArea(Areas_SAM2, std::vector<int>{153, 154, 155, 156, 157, 158, 159, 160, 161});
    RegisterArea(Areas_SAM2, std::vector<int>{162, 163, 164, 165, 166, 167, 168, 169, 170});


    RegisterArea(Areas_SAM2, std::vector<int>{171, 172, 173, 174, 175, 176, 177, 178, 179});
    RegisterArea(Areas_SAM2, std::vector<int>{177, 178, 179, 180, 181, 182, 183, 184, 185});
    RegisterArea(Areas_SAM2, std::vector<int>{183, 184, 185, 186, 187, 188, 189, 190, 191});

    RegisterArea(Areas_SAM2, std::vector<int>{192, 193, 194, 195, 196, 197, 198, 199, 200});
    RegisterArea(Areas_SAM2, std::vector<int>{198, 199, 200, 201, 202, 203, 204, 205, 206});
    RegisterArea(Areas_SAM2, std::vector<int>{204, 205, 206, 207, 208, 209, 210, 211, 212});

    RegisterArea(Areas_SAM2, std::vector<int>{213, 214, 215, 216, 217, 218, 219, 220, 221});
    RegisterArea(Areas_SAM2, std::vector<int>{219, 220, 221, 222, 223, 224, 225, 226, 227});
    RegisterArea(Areas_SAM2, std::vector<int>{225, 226, 227, 228, 229, 230, 231, 232, 233});

    RegisterArea(Areas_SAM2, std::vector<int>{234, 235, 236, 237, 238, 239, 240, 241, 242});
    RegisterArea(Areas_SAM2, std::vector<int>{243, 244, 245, 246, 247, 248, 249, 250, 251});
    RegisterArea(Areas_SAM2, std::vector<int>{252, 253, 254, 255, 256, 257, 258, 259, 260});

    RegisterArea(Areas_SAM2, std::vector<int>{261, 262, 263, 264, 265, 266, 267, 268, 269});
    RegisterArea(Areas_SAM2, std::vector<int>{270, 271, 272, 273, 274, 275, 276, 277, 278});
    RegisterArea(Areas_SAM2, std::vector<int>{279, 280, 281, 282, 283, 284, 285, 286, 287});

    /* Columns */
    RegisterArea(Areas_SAM2, std::vector<int>{ 54, 75, 96, 117, 135, 153, 171, 192, 213});
    RegisterArea(Areas_SAM2, std::vector<int>{ 55, 76, 97, 118, 136, 154, 172, 193, 214});
    RegisterArea(Areas_SAM2, std::vector<int>{ 56, 77, 98, 119, 137, 155, 173, 194, 215});
    RegisterArea(Areas_SAM2, std::vector<int>{ 57, 78, 99, 120, 138, 156, 174, 195, 216});
    RegisterArea(Areas_SAM2, std::vector<int>{ 58, 79, 100, 121, 139, 157, 175, 196, 217});
    RegisterArea(Areas_SAM2, std::vector<int>{ 59, 80, 101, 122, 140, 158, 176, 197, 218});
    RegisterArea(Areas_SAM2, std::vector<int>{ 60, 81, 102, 123, 141, 159, 177, 198, 219});
    RegisterArea(Areas_SAM2, std::vector<int>{ 61, 82, 103, 124, 142, 160, 178, 199, 220});
    RegisterArea(Areas_SAM2, std::vector<int>{ 62, 83, 104, 125, 143, 161, 179, 200, 221});

    RegisterArea(Areas_SAM2, std::vector<int>{  0, 9, 18, 27, 36, 45, 60, 81, 102});
    RegisterArea(Areas_SAM2, std::vector<int>{  1, 10, 19, 28, 37, 46, 61, 82, 103});
    RegisterArea(Areas_SAM2, std::vector<int>{  2, 11, 20, 29, 38, 47, 62, 83, 104});
    RegisterArea(Areas_SAM2, std::vector<int>{  3, 12, 21, 30, 39, 48, 63, 84, 105});
    RegisterArea(Areas_SAM2, std::vector<int>{  4, 13, 22, 31, 40, 49, 64, 85, 106});
    RegisterArea(Areas_SAM2, std::vector<int>{  5, 14, 23, 32, 41, 50, 65, 86, 107});
    RegisterArea(Areas_SAM2, std::vector<int>{  6, 15, 24, 33, 42, 51, 66, 87, 108});
    RegisterArea(Areas_SAM2, std::vector<int>{  7, 16, 25, 34, 43, 52, 67, 88, 109});
    RegisterArea(Areas_SAM2, std::vector<int>{  8, 17, 26, 35, 44, 53, 68, 89, 110});

    RegisterArea(Areas_SAM2, std::vector<int>{  66, 87, 108, 126, 144, 162, 183, 204, 225});
    RegisterArea(Areas_SAM2, std::vector<int>{  67, 88, 109, 127, 145, 163, 184, 205, 226});
    RegisterArea(Areas_SAM2, std::vector<int>{  68, 89, 110, 128, 146, 164, 185, 206, 227});
    RegisterArea(Areas_SAM2, std::vector<int>{  69, 90, 111, 129, 147, 165, 186, 207, 228});
    RegisterArea(Areas_SAM2, std::vector<int>{  70, 91, 112, 130, 148, 166, 187, 208, 229});
    RegisterArea(Areas_SAM2, std::vector<int>{  71, 92, 113, 131, 149, 167, 188, 209, 230});
    RegisterArea(Areas_SAM2, std::vector<int>{  72, 93, 114, 132, 150, 168, 189, 210, 231});
    RegisterArea(Areas_SAM2, std::vector<int>{  73, 94, 115, 133, 151, 169, 190, 211, 232});
    RegisterArea(Areas_SAM2, std::vector<int>{  74, 95, 116, 134, 152, 170, 191, 212, 233});

    RegisterArea(Areas_SAM2, std::vector<int>{  177, 198, 219, 234, 243, 252, 261, 270, 279});
    RegisterArea(Areas_SAM2, std::vector<int>{  178, 199, 220, 235, 244, 253, 262, 271, 280});
    RegisterArea(Areas_SAM2, std::vector<int>{  179, 200, 221, 236, 245, 254, 263, 272, 281});
    RegisterArea(Areas_SAM2, std::vector<int>{  180, 201, 222, 237, 246, 255, 264, 273, 282});
    RegisterArea(Areas_SAM2, std::vector<int>{  181, 202, 223, 238, 247, 256, 265, 274, 283});
    RegisterArea(Areas_SAM2, std::vector<int>{  182, 203, 224, 239, 248, 257, 266, 275, 284});
    RegisterArea(Areas_SAM2, std::vector<int>{  183, 204, 225, 240, 249, 258, 267, 276, 285});
    RegisterArea(Areas_SAM2, std::vector<int>{  184, 205, 226, 241, 250, 259, 268, 277, 286});
    RegisterArea(Areas_SAM2, std::vector<int>{  185, 206, 227, 242, 251, 260, 269, 278, 287});

    /* Blocks */
    RegisterArea(Areas_SAM2, std::vector<int>{  0, 1, 2, 9, 10, 11, 18, 19, 20});
    RegisterArea(Areas_SAM2, std::vector<int>{  3, 4, 5, 12, 13, 14, 21, 22, 23});
    RegisterArea(Areas_SAM2, std::vector<int>{  6, 7, 8, 15, 16, 17, 24, 25, 26});
    RegisterArea(Areas_SAM2, std::vector<int>{  27, 28, 29, 36, 37, 38, 45, 46, 47});
    RegisterArea(Areas_SAM2, std::vector<int>{  30, 31, 32, 39, 40, 41, 48, 49, 50});
    RegisterArea(Areas_SAM2, std::vector<int>{  33, 34, 35, 42, 43, 44, 51, 52, 53});
    RegisterArea(Areas_SAM2, std::vector<int>{  60, 61, 62, 81, 82, 83, 102, 103, 104});
    RegisterArea(Areas_SAM2, std::vector<int>{  63, 64, 65, 84, 85, 86, 105, 106, 107});
    RegisterArea(Areas_SAM2, std::vector<int>{  66, 67, 68, 87, 88, 89, 108, 109, 110});

    RegisterArea(Areas_SAM2, std::vector<int>{  54, 55, 56, 75, 76, 77, 96, 97, 98});
    RegisterArea(Areas_SAM2, std::vector<int>{  57, 58, 59, 78, 79, 80, 99, 100, 101});
    RegisterArea(Areas_SAM2, std::vector<int>{  117, 118, 119, 135, 136, 137, 153, 154, 155});
    RegisterArea(Areas_SAM2, std::vector<int>{  120, 121, 122, 138, 139, 140, 156, 157, 158});
    RegisterArea(Areas_SAM2, std::vector<int>{  123, 124, 125, 141, 142, 143, 159, 160, 161});
    RegisterArea(Areas_SAM2, std::vector<int>{  171, 172, 173, 192, 193, 194, 213, 214, 215});
    RegisterArea(Areas_SAM2, std::vector<int>{  174, 175, 176, 195, 196, 197, 216, 217, 218});
    RegisterArea(Areas_SAM2, std::vector<int>{  177, 178, 179, 198, 199, 200, 219, 220, 221});


    /*RegisterArea(Area, std::vector<int>{  66, 67, 68, 87, 88, 89, 108, 109, 110});*/
    RegisterArea(Areas_SAM2, std::vector<int>{  69, 70, 71, 90, 91, 92, 111, 112, 113});
    RegisterArea(Areas_SAM2, std::vector<int>{  72, 73, 74, 93, 94, 95, 114, 115, 116});
    RegisterArea(Areas_SAM2, std::vector<int>{  126, 127, 128, 144, 145, 146, 162, 163, 164});
    RegisterArea(Areas_SAM2, std::vector<int>{  129, 130, 131, 147, 148, 149, 165, 166, 167});
    RegisterArea(Areas_SAM2, std::vector<int>{  132, 133, 134, 150, 151, 152, 168, 169, 170});
    RegisterArea(Areas_SAM2, std::vector<int>{  183, 184, 185, 204, 205, 206, 225, 226, 227});
    RegisterArea(Areas_SAM2, std::vector<int>{  186, 187, 188, 207, 208, 209, 228, 229, 230});
    RegisterArea(Areas_SAM2, std::vector<int>{  189, 190, 191, 210, 211, 212, 231, 232, 233});

    RegisterArea(Areas_SAM2, std::vector<int>{  180, 181, 182, 201, 202, 203, 222, 223, 224});
    RegisterArea(Areas_SAM2, std::vector<int>{  234, 235, 236, 243, 244, 245, 252, 253, 254});
    RegisterArea(Areas_SAM2, std::vector<int>{  237, 238, 239, 246, 247, 248, 255, 256, 257});
    RegisterArea(Areas_SAM2, std::vector<int>{  240, 241, 242, 249, 250, 251, 258, 259, 260});
    RegisterArea(Areas_SAM2, std::vector<int>{  261, 262, 263, 270, 271, 272, 279, 280, 281});
    RegisterArea(Areas_SAM2, std::vector<int>{  264, 265, 266, 273, 274, 275, 282, 283, 284});
    RegisterArea(Areas_SAM2, std::vector<int>{  267, 268, 269, 276, 277, 278, 285, 286, 287});

}

void init_SAM2_area_txt_descs(std::vector<std::string>& Area_txt_descs_SAM2) {

    /*  Rows */
    for (int i = 0; i < 6; i++)
        Area_txt_descs_SAM2.push_back({ "UM-R" + std::to_string(i + 1) });
    for (int i = 0; i < 3; i++) {
        Area_txt_descs_SAM2.push_back({ "Lt-R" + std::to_string(i + 1)});
        Area_txt_descs_SAM2.push_back({ "UM-R" + std::to_string(i + 7) });
        Area_txt_descs_SAM2.push_back({ "Rt-R" + std::to_string(i + 1) });
    }
    for (int i = 0; i < 3; i++) {
        Area_txt_descs_SAM2.push_back({ "Lt-R" + std::to_string(i + 4) });
        Area_txt_descs_SAM2.push_back({ "Rt-R" + std::to_string(i + 4) });
    }
    for (int i = 0; i < 3; i++) {
        Area_txt_descs_SAM2.push_back({ "Lt-R" + std::to_string(i + 7) });
        Area_txt_descs_SAM2.push_back({ "LM-R" + std::to_string(i + 1) });
        Area_txt_descs_SAM2.push_back({ "Rt-R" + std::to_string(i + 7) });
    }
    for (int i = 0; i < 6; i++)
        Area_txt_descs_SAM2.push_back({ "LM-R" + std::to_string(i + 4) });



    /* Columns */
    for (int i = 0; i < 9; i++)
        Area_txt_descs_SAM2.push_back({ "Lt-C" + std::to_string(i + 1) });

    for (int i = 0; i < 9; i++)
        Area_txt_descs_SAM2.push_back({ "UM-C" + std::to_string(i + 1) });

    for (int i = 0; i < 9; i++)
        Area_txt_descs_SAM2.push_back({ "Rt-C" + std::to_string(i + 1) });

    for (int i = 0; i < 9; i++)
        Area_txt_descs_SAM2.push_back({ "LM-C" + std::to_string(i + 1) });

    /* Blocks */
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            Area_txt_descs_SAM2.push_back({ "UM-B_" + std::to_string(i + 1) + "," + std::to_string(j + 1) });
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            Area_txt_descs_SAM2.push_back({ "Lt-B_" + std::to_string(i + 1) + "," + std::to_string(j + 1) });

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            Area_txt_descs_SAM2.push_back({ "Rt-B_" + std::to_string(i + 1) + "," + std::to_string(j + 1) });
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            Area_txt_descs_SAM2.push_back({ "LM-B_" + std::to_string(i + 1) + "," + std::to_string(j + 1) });
}


void disp_SAM2(int* zadanie, ...) {
    int offset = 0;
    for (int c = 0; c < 6; c++) {
        std::cout << "      ";
        for (int i = 0; i < 9; i++)
            disp_elem(zadanie[offset + i]);
        offset += 9;
        std::cout << '\n';
    }
    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < 21; i++)
            disp_elem(zadanie[offset + i]);
        std::cout << '\n';
        offset += 21;
    }
    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < 9; i++)
            disp_elem(zadanie[offset + i]);
        offset += 9;
        std::cout << "   ";
        for (int i = 0; i < 9; i++)
            disp_elem(zadanie[offset + i]);
        offset += 9;
        std::cout << '\n';
    }
    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < 21; i++)
            disp_elem(zadanie[offset + i]);
        std::cout << '\n';
        offset += 21;
    }
    for (int c = 0; c < 6; c++) {
        std::cout << "      ";
        for (int i = 0; i < 9; i++)
            disp_elem(zadanie[offset + i]);
        offset += 9;
        std::cout << '\n';
    }
}


void init_3x3D_areas(std::vector<std::vector<int>>& Areas_3x3D) {
    /* Rows */
    for (int i = 0; i < 9; i++)
        RegisterArea(Areas_3x3D, std::vector<int>{ 9 * i + 0, 9 * i + 1, 9 * i + 2,
            9 * i + 3, 9 * i + 4, 9 * i + 5,
            9 * i + 6, 9 * i + 7, 9 * i + 8});
    /* Columns */
    for (int i = 0; i < 9; i++) {
        RegisterArea(Areas_3x3D, std::vector<int>{ i + 0, i + 9, i + 18,
            i + 27, i + 36, i + 45, i + 54, i + 63, i + 72});
    }
    /* 3x3 Blocks*/
    for (int i = 0; i < 3; i++) {
        RegisterArea(Areas_3x3D, std::vector<int>{27 * i + 0, 27 * i + 1, 27 * i + 2, 27 * i + 9, 27 * i + 10, 27 * i + 11, 27 * i + 18, 27 * i + 19, 27 * i + 20});
        RegisterArea(Areas_3x3D, std::vector<int>{27 * i + 3, 27 * i + 4, 27 * i + 5, 27 * i + 12, 27 * i + 13, 27 * i + 14, 27 * i + 21, 27 * i + 22, 27 * i + 23});
        RegisterArea(Areas_3x3D, std::vector<int>{27 * i + 6, 27 * i + 7, 27 * i + 8, 27 * i + 15, 27 * i + 16, 27 * i + 17, 27 * i + 24, 27 * i + 25, 27 * i + 26});
    }

    /* Diagonals */
    RegisterArea(Areas_3x3D, std::vector<int>{0, 10, 20, 30, 40, 50, 60, 70, 80});
    RegisterArea(Areas_3x3D, std::vector<int>{8, 16, 24, 32, 40, 48, 56, 64, 72});

}

void init_3x3_areas(std::vector<std::vector<int>>& Areas_3x3) {
    /* Rows */
    for (int j = 0; j < 9; j++) {
        std::vector<int> vec;
        for (int i = 0; i < 9; i++)
            vec.push_back(9 * j + i);
        //Areas3x3.push_back(vec);
        RegisterArea(Areas_3x3, vec);
    }
    /* Columns */
    for (int j = 0; j < 9; j++) {
        std::vector<int> vec;
        for (int i = 0; i < 9; i++)
            vec.push_back(j + 9 * i);
        //Areas3x3.push_back(vec);
        RegisterArea(Areas_3x3, vec);
    }
    /* Boards */
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            std::vector<int> vec;
            for (int i = 0; i < 3; i++)
                vec.push_back(27 * j + 3 * k + i);
            for (int i = 0; i < 3; i++)
                vec.push_back(27 * j + 3 * k + 9 + i);
            for (int i = 0; i < 3; i++)
                vec.push_back(27 * j + 3 * k + 18 + i);

            RegisterArea(Areas_3x3, vec);
        }
    }
}

void init_rect_row_areas(int size, std::vector<std::vector<int>>& Areas_rc_x_cc) {
    int rowsize, colsize;
    rowsize = colsize = size;

    /* Rows */
    for (int j = 0; j < rowsize; j++) {
        std::vector<int> vec;
        for (int i = 0; i < colsize; i++)
            vec.push_back(colsize * j + i);
        //Areas3x3.push_back(vec);
        RegisterArea(Areas_rc_x_cc, vec);
    }
}

void init_rect_row_areas_with_txt_description(int size, std::vector<std::vector<int>>& Areas_rc_x_cc, std::vector<std::string> &Areas_txt_desc) {
    int rowsize, colsize;
    rowsize = colsize = size;

    /* Rows */
    for (int j = 0; j < rowsize; j++) {
        std::vector<int> vec;
        for (int i = 0; i < colsize; i++)
            vec.push_back(colsize * j + i);
        //Areas3x3.push_back(vec);
        RegisterArea(Areas_rc_x_cc, vec);
        char buffer[10]{ "R%0" }, text_desc_str[10];
        if (rowsize >= 10)
            buffer[3] = '2';
        else
            buffer[3] = '1';
        buffer[4] = 'd';
        buffer[5] = '\0';
        sprintf(text_desc_str, buffer, j + 1);
        std::string txt_desc{ text_desc_str };
        Areas_txt_desc.push_back(text_desc_str);
    }
}


void init_rect_col_areas(int size, std::vector<std::vector<int>>& Areas_rc_x_cc) {
    int rowsize, colsize;
    rowsize = colsize = size;

    /* Columns */
    for (int j = 0; j < colsize; j++) {
        std::vector<int> vec;
        for (int i = 0; i < rowsize; i++)
            vec.push_back(j + colsize * i);
        //Areas3x3.push_back(vec);
        RegisterArea(Areas_rc_x_cc, vec);
    }
}

void init_rect_diag_areas(int size, std::vector<std::vector<int>>& Areas_rc_x_cc) {
    int rowsize, colsize;
    colsize = rowsize = size;

    /* main diagonal */
    {
        std::vector<int> vec;
        for (int i = 0; i < colsize; i++)
            vec.push_back(i * colsize + i);
        RegisterArea(Areas_rc_x_cc, vec);
    }
    /* other diagonal */
    {
        std::vector<int> vec;
        for (int i = 0; i < colsize; i++)
            vec.push_back(i * colsize + colsize - 1 - i);
        RegisterArea(Areas_rc_x_cc, vec);
    }
}

void init_rc_x_cc_areas(int rc, int cc, std::vector<std::vector<int>>& Areas_rc_x_cc, bool add_diagonals) {
    int rowsize = rc * cc;
    int colsize = rowsize;

    /* Rows */
    for (int j = 0; j < rowsize; j++) {
        std::vector<int> vec;
        for (int i = 0; i < colsize; i++)
            vec.push_back(colsize * j + i);
        //Areas3x3.push_back(vec);
        RegisterArea(Areas_rc_x_cc, vec);
    }

    /* Columns */
    for (int j = 0; j < colsize; j++) {
        std::vector<int> vec;
        for (int i = 0; i < rowsize; i++)
            vec.push_back(j + colsize * i);
        //Areas3x3.push_back(vec);
        RegisterArea(Areas_rc_x_cc, vec);
    }

    /* Sub-Areas */
    for (int u = 0; u < cc; u++) {
        for (int v = 0; v < rc; v++) {
            std::vector<int> vec;
            for (int i = 0; i < rc; i++) 
                for (int j = 0; j < cc; j++) 
                    vec.push_back(rc * colsize * u + cc * v + i * colsize + j);
                    
                
            //disp_vec(vec);
            RegisterArea(Areas_rc_x_cc, vec);
        }
    }

    /* Optional diagonals */
    if (add_diagonals) {
        /* main diagonal */
        {
            std::vector<int> vec;
            for (int i = 0; i < colsize; i++)
                vec.push_back(i * colsize + i);
            RegisterArea(Areas_rc_x_cc, vec);
        }
        /* other diagonal */
        {
            std::vector<int> vec;
            for (int i = 0; i < colsize; i++)
                vec.push_back(i * colsize + colsize - 1 - i);
            RegisterArea(Areas_rc_x_cc, vec);
        }
    }
}

void init_rc_x_cc_area_descs(int rc, int cc, std::vector<std::string>& Area_descs_rc_x_cc, bool add_diagonals) {
    int rowsize = rc * cc;
    int colsize = rowsize;

    /* Rows */
    for (int j = 0; j < rowsize; j++) {
        std::vector<int> vec;
        for (int i = 0; i < colsize; i++)
            vec.push_back(colsize * j + i);
        //Areas3x3.push_back(vec);
        std::string txt_desc = "R" + std::to_string(j + 1);
        Area_descs_rc_x_cc.push_back(txt_desc);
    }

    /* Columns */
    for (int j = 0; j < colsize; j++) {
        std::vector<int> vec;
        for (int i = 0; i < rowsize; i++)
            vec.push_back(j + colsize * i);
        //Areas3x3.push_back(vec);
        std::string txt_desc = "C" + std::to_string(j + 1);
        Area_descs_rc_x_cc.push_back(txt_desc);
    }

    /* Sub-Areas */
    for (int u = 0; u < cc; u++) {
        for (int v = 0; v < rc; v++) {
            std::string txt_desc = "B-" + std::to_string(u + 1) + "," + std::to_string(v + 1);
            Area_descs_rc_x_cc.push_back(txt_desc);
        }
    }

    /* Optional diagonals */
    if (add_diagonals) {
        /* main diagonal */
        {
            std::string txt_desc = "D1";
            Area_descs_rc_x_cc.push_back(txt_desc);
        }
        /* other diagonal */
        {
            std::string txt_desc = "D2";
            Area_descs_rc_x_cc.push_back(txt_desc);
        }
    }
}



void init_SAM_areas(std::vector<std::vector<int>> &Areas_SAM) {
    ;
    int offset = 0; /* offset var */
    /* Rows */
    for (int i = 0; i < 12; i++) {
        std::vector<int> vec;

        for (int j = 0; j < 9; j++)
            vec.push_back(9 * i + j);

        RegisterArea(Areas_SAM, vec);
    }
    offset = 108;
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 3; i++) {
            std::vector<int> vec;

            for (int k = 0; k < 9; k++)
                vec.push_back(offset + 21 * j + 6 * i + k);

            RegisterArea(Areas_SAM, vec);
        }
    offset = 171;
    for (int i = 0; i < 3; i++) {
        std::vector<int> vec;

        for (int j = 0; j < 9; j++)
            vec.push_back(offset + 9 * i + j);

        RegisterArea(Areas_SAM, vec);

    }
    offset = 198;
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 3; i++) {
            std::vector<int> vec;

            for (int k = 0; k < 9; k++)
                vec.push_back(offset + 21 * j + 6 * i + k);

            RegisterArea(Areas_SAM, vec);
        }
    //RegisterArea(Areas_Sam, std::vector<int>{
    //offset + 21 * j + 6 * i + 0, offset + 21 * j + 6 * i + 1, offset + 21 * j + 6 * i + 2,
    //    offset + 21 * j + 6 * i + 21, offset + 21 * j + 6 * i + 22, offset + 21 * j + 6 * i + 23,
    //    offset + 21 * j + 6 * i + 42, offset + 21 * j + 6 * i + 43, offset + 21 * j + 6 * i + 44});
    offset = 261;
    for (int i = 0; i < 12; i++) {
        std::vector<int> vec;

        for (int j = 0; j < 9; j++)
            vec.push_back(offset + 9 * i + j);

        RegisterArea(Areas_SAM, vec);
    }

    /* Columns */
    for (int i = 0; i < 9; i++)
        RegisterArea(Areas_SAM, std::vector<int>{i + 0, i + 18, i + 36, i + 54, i + 72, i + 90, i + 108, i + 129, i + 150});
    for (int i = 0; i < 9; i++)
        RegisterArea(Areas_SAM, std::vector<int>{i + 9, i + 27, i + 45, i + 63, i + 81, i + 99, i + 120, i + 141, i + 162});
    for (int i = 0; i < 9; i++)
        RegisterArea(Areas_SAM, std::vector<int>{i + 114, i + 135, i + 156, i + 171, i + 180, i + 189, i + 204, i + 225, i + 246});
    for (int i = 0; i < 9; i++)
        RegisterArea(Areas_SAM, std::vector<int>{i + 198, i + 219, i + 240, i + 261, i + 279, i + 297, i + 315, i + 333, i + 351});
    for (int i = 0; i < 9; i++)
        RegisterArea(Areas_SAM, std::vector<int>{i + 210, i + 231, i + 252, i + 270, i + 288, i + 306, i + 324, i + 342, i + 360});

    /* Blocks */
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < 6; i++)
            RegisterArea(Areas_SAM, std::vector<int>{
            54 * j + 3 * i + 0, 54 * j + 3 * i + 1, 54 * j + 3 * i + 2,
                54 * j + 3 * i + 18, 54 * j + 3 * i + 19, 54 * j + 3 * i + 20,
                54 * j + 3 * i + 36, 54 * j + 3 * i + 37, 54 * j + 3 * i + 38});

    offset = 108;
    for (int i = 0; i < 7; i++)
        RegisterArea(Areas_SAM, std::vector<int>{
        offset + 3 * i + 0, offset + 3 * i + 1, offset + 3 * i + 2,
            offset + 3 * i + 21, offset + 3 * i + 22, offset + 3 * i + 23,
            offset + 3 * i + 42, offset + 3 * i + 43, offset + 3 * i + 44});
    offset = 171;
    for (int i = 0; i < 3; i++)
        RegisterArea(Areas_SAM, std::vector<int>{
        offset + 3 * i + 0, offset + 3 * i + 1, offset + 3 * i + 2,
            offset + 3 * i + 9, offset + 3 * i + 10, offset + 3 * i + 11,
            offset + 3 * i + 18, offset + 3 * i + 19, offset + 3 * i + 20});
    offset = 198;
    for (int i = 0; i < 7; i++)
        RegisterArea(Areas_SAM, std::vector<int>{
        offset + 3 * i + 0, offset + 3 * i + 1, offset + 3 * i + 2,
            offset + 3 * i + 21, offset + 3 * i + 22, offset + 3 * i + 23,
            offset + 3 * i + 42, offset + 3 * i + 43, offset + 3 * i + 44});
    offset = 261;
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < 6; i++)
            RegisterArea(Areas_SAM, std::vector<int>{
            offset + 54 * j + 3 * i + 0, offset + 54 * j + 3 * i + 1, offset + 54 * j + 3 * i + 2,
                offset + 54 * j + 3 * i + 18, offset + 54 * j + 3 * i + 19, offset + 54 * j + 3 * i + 20,
                offset + 54 * j + 3 * i + 36, offset + 54 * j + 3 * i + 37, offset + 54 * j + 3 * i + 38});

}

void init_SAM_area_txt_descs(std::vector<std::string>& Area_txt_descs_SAM) {
    /* Rows */
    for (int i = 0; i < 6; i++) {
        Area_txt_descs_SAM.push_back({ "ULt-R" + std::to_string(i + 1) });
        Area_txt_descs_SAM.push_back({ "URt-R" + std::to_string(i + 1) });
    }
    for (int i = 0; i < 3; i++) {
        Area_txt_descs_SAM.push_back({ "ULt-R" + std::to_string(i + 7) });
        Area_txt_descs_SAM.push_back({ "Mid-R" + std::to_string(i + 1) });
        Area_txt_descs_SAM.push_back({ "Urt-R" + std::to_string(i + 7) });
    }
    for (int i = 0; i < 3; i++) {
        Area_txt_descs_SAM.push_back({ "Mid-R" + std::to_string(i + 4) });
    }
    for (int i = 0; i < 3; i++) {
        Area_txt_descs_SAM.push_back({ "LLt-R" + std::to_string(i + 1) });
        Area_txt_descs_SAM.push_back({ "Mid-R" + std::to_string(i + 7) });
        Area_txt_descs_SAM.push_back({ "Lrt-R" + std::to_string(i + 1) });
    }
    for (int i = 0; i < 6; i++) {
        Area_txt_descs_SAM.push_back({ "LLt-R" + std::to_string(i + 4) });
        Area_txt_descs_SAM.push_back({ "LRt-R" + std::to_string(i + 4) });
    }

    /* Columns */
    for (int i = 0; i < 9; i++) 
        Area_txt_descs_SAM.push_back({ "ULt-C" + std::to_string(i + 1) });

    for (int i = 0; i < 9; i++)
        Area_txt_descs_SAM.push_back({ "URt-C" + std::to_string(i + 1) });

    for (int i = 0; i < 9; i++)
        Area_txt_descs_SAM.push_back({ "Mid-C" + std::to_string(i + 1) });
        
    for (int i = 0; i < 9; i++)
        Area_txt_descs_SAM.push_back({ "LLt-C" + std::to_string(i + 1) });
        
    for (int i = 0; i < 9; i++)
        Area_txt_descs_SAM.push_back({ "LRt-C" + std::to_string(i + 1) });

    /* Blocks */
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < 3; i++) {
            Area_txt_descs_SAM.push_back({ "ULt-B_" + std::to_string(j + 1) + "," + std::to_string(i + 1) });
            Area_txt_descs_SAM.push_back({ "URt-B_" + std::to_string(j + 1) + "," + std::to_string(i + 1) });
        }
    
    Area_txt_descs_SAM.push_back({ "ULt-B_3,1" });
    Area_txt_descs_SAM.push_back({ "ULt-B_3,2" });
    Area_txt_descs_SAM.push_back({ "ULt-B_3,3 = Mid-B_1,1" });
    Area_txt_descs_SAM.push_back({ "Mid-B_1,2" });
    Area_txt_descs_SAM.push_back({ "URt-B_3,1 = Mid-B_1,3" });
    Area_txt_descs_SAM.push_back({ "URt-B_3,2" });
    Area_txt_descs_SAM.push_back({ "URt-B_3,3" });
    for (int i = 0; i < 3; i++)
        Area_txt_descs_SAM.push_back({ "Mid-B_2," + std::to_string(i+1) });
    Area_txt_descs_SAM.push_back({ "LLt-B_1,1" });
    Area_txt_descs_SAM.push_back({ "LLt-B_1,2" });
    Area_txt_descs_SAM.push_back({ "LLt-B_1,3 = Mid-B_3,1" });
    Area_txt_descs_SAM.push_back({ "Mid-B_3,2" });
    Area_txt_descs_SAM.push_back({ "Mid-B_3,3 = LRt-B_1,1" });
    Area_txt_descs_SAM.push_back({ "LRt-B_1,2" });
    Area_txt_descs_SAM.push_back({ "LRt-B_1,3" });

    for (int j = 0; j < 2; j++)
        for (int i = 0; i < 3; i++) {
            Area_txt_descs_SAM.push_back({ "LLt-B_" + std::to_string(j + 2) + "," + std::to_string(i + 1) });
            Area_txt_descs_SAM.push_back({ "LRt-B_" + std::to_string(j + 2) + "," + std::to_string(i + 1) });
        }
}


/* diagonal n x n without blocks
 * Areas - rows, columns and 2 diagonals */

void init_STDBareD_areas(int n, std::vector<std::vector<int>>& STDBareD_areas) {
    /* Rows */
    for (int i = 0; i < n; i++) {
        std::vector<int> vec;
        for (int j = 0; j < n; j++)
            vec.push_back(n * i + j);
        RegisterArea(STDBareD_areas, vec);
    }
    /* Columns */
    for (int i = 0; i < n; i++) {
        std::vector<int> vec;
        for (int j = 0; j < n; j++)
            vec.push_back(i + n * j);
        RegisterArea(STDBareD_areas, vec);
    }
    /* Diagonals */
    /* Main */
    {
        std::vector<int> vec;
        for (int i = 0; i < n; i++)
            vec.push_back(n * i + i);
        RegisterArea(STDBareD_areas, vec);
    }
    /* Side */
    {
        std::vector<int> vec;
        for (int i = 0; i < n; i++)
            vec.push_back(n * i + n - 1 - i);
        RegisterArea(STDBareD_areas, vec);
    }
}

/*

+--+--+--+--+
|.. ..|.. ..|  00 01   02 03 | 04 05   06 07
|.. ..|.. ..|  08 09   10 11 | 12 13   14 15
+--+--+--+--+  ------+-------+-------+-------
|..|.. ..|..|  16 17 | 18 19   20 21 | 22 23
|..|.. ..|..|  24 25 | 26 27   28 20 | 30 31
|  +-----+  |        +-------------+
|..|.. ..|..|  32 33 | 34 35   36 37 | 38 39
|..|.. ..|..|  40 41 | 42 43   44 45 | 46 47
+--+--+--+--+  ------+-------+-----+-------
|..|.. ..|..|  48 49   50 51 | 52 53   54 55
|..|.. ..|..|  56 57   58 59 | 60 61   62 63
+--+--+--+--+  

*/

std::vector<std::vector<int>> region_template_T8 = {
    {1,1,1,1,2,2,2,2},
    {1,1,1,1,2,2,2,2},
    {3,3,4,4,4,4,5,5},
    {3,3,4,4,4,4,5,5},
    {3,3,6,6,6,6,5,5},
    {3,3,6,6,6,6,5,5},
    {7,7,7,7,8,8,8,8},
    {7,7,7,7,8,8,8,8}
};

std::vector<std::vector<int>> region_template_T9 = 
{
    {1,1,1,2,2,2,3,3,3},
    {1,1,1,1,2,3,3,3,3},
    {1,4,1,2,2,2,3,6,3},
    {4,4,4,2,5,2,6,6,6},
    {4,5,5,5,5,5,5,5,6},
    {4,4,4,8,5,8,6,6,6},
    {7,4,7,8,8,8,9,6,9},
    {7,7,7,7,8,9,9,9,9},
    {7,7,7,8,8,8,9,9,9}

};

std::vector<std::vector<int>> region_template_T9_15 =
{
    { 1,1,1,1,2,2,2,2,2 },
    { 3,3,3,1,1,2,2,2,2 },
    { 3,3,3,4,1,1,5,5,5 },
    { 6,3,3,4,4,1,5,5,5 },
    { 6,6,3,4,4,4,7,5,5 },
    { 6,6,6,8,4,4,7,7,5 },
    { 6,6,6,8,8,4,7,7,7 },
    { 9,9,9,9,8,8,7,7,7 },
    { 9,9,9,9,9,8,8,8,8 }
};

std::vector<std::vector<int>> region_template_T9_17 =
{
    {1,1,1,1,1,2,2,2,2},
    {1,1,3,3,3,4,4,2,2},
    {1,3,3,3,3,4,4,4,2},
    {1,3,3,5,5,5,4,4,2},
    {6,7,7,5,5,5,4,4,2},
    {6,7,7,5,5,5,8,8,9},
    {6,7,7,7,8,8,8,8,9},
    {6,6,7,7,8,8,8,9,9},
    {6,6,6,6,9,9,9,9,9}
};



std::vector<std::vector<int>> generate_areas_from_region_template(std::vector<std::vector<int>>& region_template) {
    // number of regions
    int n_reg = static_cast<int>(region_template.size());
    // std::cout << n_reg << '\n';

    std::vector<std::vector<int>> res_vec;
    for (int nr = 0; nr < n_reg; nr++) {
        res_vec.push_back(std::vector<int>());
    }

    for (int r = 0; r < n_reg; r++)
        for (int c = 0; c < n_reg; c++) {
            int regId = region_template[r][c];
            int elemIdx = r * n_reg + c;

            res_vec[regId - 1].push_back(elemIdx);
            // std::cout << regId << ", " << elemIdx << '\n';
        }

    return res_vec;
}

bool read_region_template_from_file(std::ifstream& ifs, int n_dim, std::vector<std::vector<int>> &region_template)
{
    char buffer[1024];
    // Read region_map
    int introw = 0;
    int intcol = 0;
    bool map_enough = false;

    //std::vector<std::vector<int>> region_template;
    for (int i = 0; i < n_dim; i++) {
        region_template.push_back(std::vector<int>());
        for (int j = 0; j < n_dim; j++)
            region_template[i].push_back(0);
    }

    do {
        ifs.getline(buffer, 1024);
        if (ifs.good() && !map_enough) {
            char* pom = buffer;

            //cout << buffer <<endl;
            // skipws
            while (*pom && (*pom == ' ' || *pom == '\t')) pom++;

            // skip comment lines and empty lines
            if (*pom == '#' || !*pom)
                continue;

            while (*pom) {
                int val = 0;
                //readnumber
                while (*pom >= '0' && *pom <= '9') {
                    val = 10 * val + (*pom - '0');
                    pom++;
                }
                if (val > 0) {
                    //cout << "C:" << intcol << " R:" << introw << " V:" << val << endl;	
                    region_template[introw][intcol] = val;
                    intcol++;


                }
                
                if (intcol == n_dim)
                    break;

                //skipws
                while (*pom && (*pom == ' ' || *pom == '\t')) pom++;
                //skipdelimiter ','
                if (*pom != ',') {
                    std::cout << "'" << *pom << "'" << '\n';
                    std::cerr << "Missing , ." << '\n';
                    return false;
                }
                else pom++;
                //skipws
                while (*pom && (*pom == ' ' || *pom == '\t')) pom++;

            }
            introw++;
            intcol = 0;
            if (introw == n_dim)
                map_enough = true;

        }

    } while (ifs.good() && !map_enough);

    return true;
}

#if 0
if (region_read)
{

    //skip - emptyres_template line
    infile.getline(buffer, 512);

    // Read region_map
    intcol = 0;
    introw = 0;
    do {

        infile.getline(buffer, 512);
        if (infile.good() && !map_enough) {
            char* pom = buffer;

            //cout << buffer <<endl;
            // skipws
            while (*pom && (*pom == ' ' || *pom == '\t')) pom++;

            while (*pom) {
                int val = 0;
                //readnumber
                while (*pom >= '0' && *pom <= '9') {
                    val = 10 * val + (*pom - '0');
                    pom++;
                }
                if (val > 0) {
                    //cout << "C:" << intcol << " R:" << introw << " V:" << val << endl;	
                    regionmap[intcol][introw] = val;
                    intcol++;


                }
                if (intcol == rowsize * colsize)
                    break;

                //skipws
                while (*pom && (*pom == ' ' || *pom == '\t')) pom++;
                //skipdelimiter ','
                if (*pom != ',') {
                    cout << "'" << *pom << "'" << endl;
                    cerr << "Missing , ." << endl;
                    infile.close();
                    return false;
                }
                else pom++;
                //skipws
                while (*pom && (*pom == ' ' || *pom == '\t')) pom++;

            }
            introw++;
            intcol = 0;
            if (introw == rowsize * colsize)
                map_enough = true;

        }

    } while (infile.good() && !map_enough);
}
    }

#endif



void init_RegT8_areas(std::vector<std::vector<int>>& RegT8_areas) {
    /* rows */
    for (int i = 0; i < 8; i++) {
        std::vector<int> vec;
        for (int j = 0; j < 8; j++)
            vec.push_back(8 * i + j);
        //std::cout << "DDD: ";
        //disp_vec(vec);
        RegisterArea(RegT8_areas, vec);
    }
    /* columns */
    for (int i = 0; i < 8; i++) {
        std::vector<int> vec;
        for (int j = 0; j < 8; j++)
            vec.push_back(i + 8 * j);
        RegisterArea(RegT8_areas, vec);
    }
    /* blocks */
    RegisterArea(RegT8_areas, std::vector<int>{0, 1, 2, 3, 8, 9, 10, 11});
    RegisterArea(RegT8_areas, std::vector<int>{4, 5, 6, 7, 12, 13, 14, 15});
    RegisterArea(RegT8_areas, std::vector<int>{16, 17, 24, 25, 32, 33, 40, 41});
    RegisterArea(RegT8_areas, std::vector<int>{18, 19, 20, 21, 26, 27, 28, 29});
    RegisterArea(RegT8_areas, std::vector<int>{22, 23, 30, 31, 38, 39, 46, 47});
    RegisterArea(RegT8_areas, std::vector<int>{34, 35, 36, 37, 42, 43, 44, 45});
    RegisterArea(RegT8_areas, std::vector<int>{48, 49, 50, 51, 56, 57, 58, 59});
    RegisterArea(RegT8_areas, std::vector<int>{52, 53, 54, 55, 60, 61, 62, 63});
}

void init_RegT9_1_areas(std::vector<std::vector<int>> &Areas_RegT9_1) {
    
    /*Rows*/
    for (int j = 0; j < 9; j++) {
        std::vector<int> vec;
        for (int i = 0; i < 9; i++)
            vec.push_back(9 * j + i);
        //Areas3x3.push_back(vec);
        RegisterArea(Areas_RegT9_1, vec);
    }
    /*Columns*/
    for (int j = 0; j < 9; j++) {
        std::vector<int> vec;
        for (int i = 0; i < 9; i++)
            vec.push_back(j + 9 * i);
        //Areas3x3.push_back(vec);
        RegisterArea(Areas_RegT9_1, vec);
    }
    /*Blocks*/
    RegisterArea(Areas_RegT9_1, std::vector<int>{ 0, 1, 2, 9, 10, 11, 12, 18, 20 });
    RegisterArea(Areas_RegT9_1, std::vector<int>{ 3, 4, 5, 13, 21, 22, 23, 30, 32 });
    RegisterArea(Areas_RegT9_1, std::vector<int>{ 6, 7, 8, 14, 15, 16, 17, 24, 26 });
    RegisterArea(Areas_RegT9_1, std::vector<int>{ 19, 27, 28, 29, 36, 45, 46, 47, 55 });
    RegisterArea(Areas_RegT9_1, std::vector<int>{ 31, 37, 38, 39, 40, 41, 42, 43, 49 });
    RegisterArea(Areas_RegT9_1, std::vector<int>{ 25, 33, 34, 35, 44, 51, 52, 53, 61 });
    RegisterArea(Areas_RegT9_1, std::vector<int>{ 54, 56, 63, 64, 65, 66, 72, 73, 74 });
    RegisterArea(Areas_RegT9_1, std::vector<int>{ 48, 50, 57, 58, 59, 67, 75, 76, 77 });
    RegisterArea(Areas_RegT9_1, std::vector<int>{ 60, 62, 68, 69, 70, 71, 78, 79, 80 });

}

int zadanie[] =
{ 
              0,6,0, 0,8,0, 0,7,0,
              7,0,9, 0,0,0, 4,0,2,
              0,8,0, 0,9,0, 0,1,0,
              0,0,3, 0,0,0, 2,0,0,
              0,0,0, 6,3,5, 0,0,0,
              4,0,6, 0,0,0, 3,0,5,
0,6,0, 0,0,9, 0,0,0, 9,0,1, 0,0,0, 1,0,0, 0,9,0,
2,0,9, 0,0,0, 0,0,0, 2,0,8, 0,0,0, 0,0,0, 7,0,8,
0,1,0, 2,0,3, 0,0,0, 5,0,3, 0,0,0, 8,0,6, 0,4,0,
0,0,0, 0,2,0, 8,1,3,        1,6,3, 0,5,0, 0,0,0,
1,0,3, 0,7,0, 0,0,0,        0,0,0, 0,6,0, 8,0,5,
0,0,0, 0,8,1, 4,7,6,        5,7,8, 0,2,0, 0,0,0,
0,7,0, 4,0,2, 0,0,0, 8,0,2, 0,0,0, 6,0,3, 0,5,0,
4,0,1, 0,0,0, 0,0,0, 9,0,4, 0,0,0, 0,0,0, 9,0,6,
0,5,0, 0,0,7, 0,0,0, 7,0,1, 0,0,0, 5,0,0, 0,7,0,
              2,0,1, 0,0,0, 9,0,8,
              0,0,0, 4,2,8, 0,0,0,
              0,0,3, 0,0,0, 2,0,0,
              0,9,0, 0,4,0, 0,2,0,
              4,0,7, 0,0,0, 5,0,9,
              0,2,0, 0,1,0, 0,7,0
};


/*
   Generate mapping between elementIdx and vector of areaIdxs.

   (Area is vector of vectors of elementIdxs.)
*/
void BuildMap(std::map<int, std::vector<int>>& InverseMap, std::vector<std::vector<int>>& Areas) {
    int idxArea = 0;
    for (auto &area : Areas) {
        for (auto &elemIdx : area) {
            auto iter = InverseMap.find(elemIdx);
            if (iter != InverseMap.end())
                (iter->second).push_back(idxArea);
            else
                InverseMap.insert(std::pair<int, std::vector<int>>{elemIdx, { idxArea }});
        }
        idxArea++;
    }
}

/*
    Returns the list of canditates for filling the element with elemIdx

    It also checks the consistency of the current zadanie. No area should not contain the same filled numbers.

    b_disp = true - print debug information to cerr
*/
std::vector<int> get_candidates(int elemIdx, int *zadanie, const std::vector<std::vector<int>>& Area, const std::map<int, std::vector<int>>& InverseMap, bool b_disp /*= true*/) {
        
    // how many elements to fill
    int area_size = static_cast<int>(Area[0].size());
    //std::cout << "SIZ: " << area_size;

    // create vector of size `area_size'
    std::vector<int> filled_elements;
    for (int i = 0; i < area_size; i++)
        filled_elements.push_back(0);
    
    for (auto areaIdx : InverseMap.at(elemIdx)) { //[elemIdx]
        std::vector<int> area_filled_elements;
        for (int ii = 0; ii < area_size; ii++)
            area_filled_elements.push_back(0);
    
        for (auto areaElemIdx : Area[areaIdx]) {
            int elemVal = zadanie[areaElemIdx];
            if (elemVal != 0) {
                if (area_filled_elements[elemVal - 1] != 0) {
                    if (b_disp) {
                        //std::cerr << "HHHHH\n";
                        std::cerr << "Block with index " << areaIdx << " contains more than one element " << elemVal << ".\n";
                        disp_vec(Area[areaIdx], std::cerr);
                    }
                    return std::vector<int>();
                }
                else
                    area_filled_elements[elemVal - 1]++;
                filled_elements[elemVal - 1]++;
            }
        }
    }
    
    std::vector<int> res;
    for (int elemVal = 0; elemVal < area_size; elemVal++)
        if (!filled_elements[elemVal])
            res.push_back(elemVal + 1);
    return res;
    
}

void disp_vec(const std::vector<int>& vec, std::ostream& os) {
    int idx = 0;
    for (auto e : vec) {
        if (idx > 0)
            os << ", ";
        os << e;
        idx++;
    }
    os << '\n';
}

int count_filled(int zadanie_size, int *zadanie) {
    int res = 0;
    for (int i = 0; i < zadanie_size; i++)
        if (zadanie[i] == 0) {
            res++;
        }
    return res;
}

bool is_possible_to_fill_elem_into_area(int elemVal, int areaIdx, int* zadanie, const std::vector<std::vector<int>>& Area, const std::map<int, std::vector<int>>& InverseMap) {
    // if already filled return true

    for (auto e_idx : Area[areaIdx]) {
        if (zadanie[e_idx] == elemVal)
            return true;
        if (zadanie[e_idx] == 0) {
            // if it is unfilled
            auto v = get_candidates(e_idx, zadanie, Area, InverseMap, false);
            if (v.size() == 0)
                return false;
            if (std::find(v.begin(), v.end(), elemVal) != v.end())
                return true;
        }
    }
    return false;
}



std::vector<std::pair<int, int>> can_be_uniquely_filled_in_area(int areaIdx, int *zadanie, const std::vector<std::vector<int>>& Area, const std::map<int, std::vector<int>>& InverseMap) {
    /* 
        
    */
    // how many elements to fill
    int area_size = static_cast<int>(Area[0].size());

    // create vector of size `area_size'
    std::vector<int> can_be_filled_times;
    std::vector<int> last_area_contained;
    for (int i = 0; i < area_size; i++) {
        can_be_filled_times.push_back(0);
        last_area_contained.push_back(0);
    }

    for (auto elemIdx : Area[areaIdx]) {
        if (zadanie[elemIdx] == 0) {
            auto v = get_candidates(elemIdx, zadanie, Area, InverseMap, false);

            for (auto elemVal : v) {
                can_be_filled_times[elemVal - 1]++;
                last_area_contained[elemVal - 1] = elemIdx;
            }
        }
    }

    std::vector<std::pair<int, int>> res;
    for (int elemVal = 0; elemVal < area_size; elemVal++)
        if (can_be_filled_times[elemVal] == 1) {
            res.push_back({ last_area_contained[elemVal], elemVal + 1 });
        }
    return res;
}

void init_candidates(int zadanie_size, int* zadanie, const std::vector<std::vector<int>> &Areas, const std::map<int, std::vector<int>> &InverseMap, std::map<int, std::set<int>> &candidates) {
    std::cout << zadanie_size << '\n';
    for (int elemIdx = 0; elemIdx < zadanie_size; elemIdx++) {
        if (zadanie[elemIdx] == 0) {
            auto v = get_candidates(elemIdx, zadanie, Areas, InverseMap, false);
            std::set<int> icands{};
            //ed.display_element_address(std::cout, elemIdx);
            //std::cout << ": ";
            for (auto e : v) {
                icands.insert(e);
                //std::cout << e << ", ";
            }
            //std::cout << '\n';
            candidates.insert(std::pair<int, std::set<int>>(elemIdx, icands));
        }
    }
}

void debug_show_set(const std::set<int>& s) {
    for (auto el : s) {
        std::cout << el << ", ";
    }
    std::cout << '\n';
}

void disp_candidates(const std::map<int, std::set<int>>& candidates) {
    for (auto val : candidates) {
        std::cout << val.first << ": ";
        for (auto el : val.second) {
            std::cout << el << ", ";
        }
        std::cout << '\n';
    }

    //for (auto &k : candidates) {
    //    std::cout << k.first << ": ";// << k.second;
    //    for (auto &s : candidates.at(k.first))
    //        for (int e : s)
    //           std::cout << e << ", ";
    //    std::cout << '\n';
    //}
}

std::vector<std::pair<int, int>> can_be_uniquely_filled_in_area2(int areaIdx, int* zadanie, std::map<int, std::set<int>> &candidates, const std::vector<std::vector<int>>& Area, const std::map<int, std::vector<int>>& InverseMap) {
    /*

    */
    // how many elements to fill
    int area_size = static_cast<int>(Area[0].size());

    // create vector of size `area_size'
    std::vector<int> can_be_filled_times;
    std::vector<int> last_area_contained;
    for (int i = 0; i < area_size; i++) {
        can_be_filled_times.push_back(0);
        last_area_contained.push_back(0);
    }

    for (auto elemIdx : Area[areaIdx]) {
        if (zadanie[elemIdx] == 0) {
            auto v = candidates[elemIdx]; // get_candidates(elemIdx, zadanie, Area, InverseMap, false);

            for (auto elemVal : v) {
                can_be_filled_times[elemVal - 1]++;
                last_area_contained[elemVal - 1] = elemIdx;
            }
        }
    }

    std::vector<std::pair<int, int>> res;
    for (int elemVal = 0; elemVal < area_size; elemVal++)
        if (can_be_filled_times[elemVal] == 1) {
            res.push_back({ last_area_contained[elemVal], elemVal + 1 });
        }
    return res;
}


void disp_zadanie(int(&zadanie)[288]) {
    /* 1st - 6th row */
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 6; i++)
            std::cout << " ";
        for (int i = 0; i < 9; i++)
            if (zadanie[9*j+i])
                std::cout << zadanie[9 * j + i];
            else std::cout << '.';
        std::cout << '\n';
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 21; i++) {
            int idx = 21 * j + 54 + i;
            if (zadanie[idx])
                std::cout << zadanie[idx];
            else std::cout << '.';
        }
        std::cout << '\n';
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 9; i++) {
            int idx = 117 + 18 * j + i;
            if (zadanie[idx])
                std::cout << zadanie[idx];
            else std::cout << '.';
        }
        std::cout << "   ";
        for (int i = 0; i < 9; i++) {
            int idx = 117 + 18 * j + 9+ i;
            if (zadanie[idx])
                std::cout << zadanie[idx];
            else std::cout << '.';
        }
        std::cout << '\n';
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 21; i++) {
            int idx = 21 * j + 171 + i;
            if (zadanie[idx])
                std::cout << zadanie[idx];
            else std::cout << '.';
        }
        std::cout << '\n';
    }

    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 6; i++)
            std::cout << " ";
        for (int i = 0; i < 9; i++)
            if (zadanie[234 + 9 * j + i])
                std::cout << zadanie[234 + 9 * j + i];
            else std::cout << '.';
        std::cout << '\n';
    }

}

bool read_region_map(std::ifstream& infile, std::vector<std::vector<int>>& Areas, int size) {
    std::vector<std::vector<int>> vecs;
    for (int i = 0; i < size; i++)
        vecs.push_back(std::vector<int>{});

    char buffer[1024];

    if (!infile.good()) {
        std::cerr << "File not open.\n";
        return false;
    }

    int rows = 0, cols = 0;
    do {
        infile.getline(buffer, 1024);
        if (infile.good()) {
            char* pom = buffer;
            while (*pom && cols < size) {
                skip_ws(pom);

                if (*pom == '#') {
                    *pom = '\0';
                    continue;
                }

                if (*pom >= '1' && *pom <= '9') {
                    int value = 0;
                    while (*pom >= '0' && *pom <= '9') {
                        value = 10 * value + (*pom - '0');
                        pom++;
                    }
                    if (value <= 0 || value > size) {
                        std::cerr << "Region number (" << value << ") must be in range [1, " << size << "].\n";
                        std::cerr << buffer << '\n';
                        for (int i = 0; i < pom - buffer; i++)
                            std::cerr << " ";
                        std::cerr << "^\n";
                        return false;
                    }
                    //std::cerr << "E: " << value << ", " << rows << ", " << cols << '\n';
                    vecs[value-1].push_back(size * rows + cols);
                    //std::cout << value;
                    
                    skip_ws(pom);
                    if (cols < size - 1) {
                        if (*pom != ',') {
                            std::cerr << "Expecting delimiter - a comma.\n";
                            std::cerr << buffer << '\n';
                            for (int i = 0; i < pom - buffer; i++)
                                std::cerr << " ";
                            std::cerr << "^\n";
                            return false;
                        }
                        else
                            pom++;
                    }
                    cols++;
                }
                else {
                    std::cerr << "Expecting number.\n";
                    std::cerr << buffer << '\n';
                    for (int i = 0; i < pom - buffer; i++)
                        std::cerr << " ";
                    std::cerr << "^\n";
                    return false;
                }
            }
            if (cols == size) {
                rows++;
                cols = 0;
            }
        }
    } while (rows < size && infile.good());
    
    if (rows != size) {
        std::cerr << "Not enough lines available.\n";
        return false;
    }

    /* Test whether areas have length size */
    int idx = 1;
    for (auto &e : vecs) {
        if (e.size() != size) {
            std::cerr << "Area with number " << idx << " has length " << e.size() << ", but expecting the lenth " << size << ".\n";
            return false;
        }
        
        idx++;
    }

    /* Store vecs into Areas */
    for (auto &e : vecs) {
        Areas.push_back(e);
    }

    /* DEBUG */
    /*std::cout << "Read areas:\n";
    for (auto e : vecs) {
        disp_vec(e);
        std::cout << "\n";
    }*/

    return true;
}

bool read_region_map(std::string& filename, std::vector<std::vector<int>>& Areas, int size) {
    std::ifstream infile;
    infile.open(filename, std::ifstream::in);
    
    if (!infile.good()) {
        std::cerr << "Error opening region file \"" << filename << "\"." << std::endl;
        infile.close();
        return false;
    }

    bool status = read_region_map(infile, Areas, size);

    infile.close();
    return status;
}


int SolveSudoku2(int zadanie_size, int* zadanie, std::vector<std::vector<int>>& Area, std::map<int, std::vector<int>>& InverseMap, std::vector<int> &filled_indices, int indent_level = 0, bool bDisp = true) {
    int e_f = 0;
    bool filled = true;
    int j = 0;
    while (filled) {
        if (bDisp) {
            apply_indent(indent_level);
            std::cerr << "Iteration " << j + 1 << ": \n";
        }
        filled = false;

        // find elements which are uniquely fillable as 
        // intersection of blocks
        std::vector<std::pair<int, int>> sfe;
        for (int elemIdx = 0; elemIdx < zadanie_size; elemIdx++) {
            if (zadanie[elemIdx] == 0) {
                auto cands = get_candidates(elemIdx, zadanie, Area, InverseMap);
                if (cands.size() == 1) {
                    sfe.push_back(std::pair<int, int>{elemIdx, cands[0]});
                    //zadanie[i] = cands[0];
                    //no_filled--;
                    //e_f++;
                    if (bDisp) {
                        apply_indent(indent_level);
                        std::cerr << " SFE: " << elemIdx << " -> " << cands[0] << '\n';
                    }
                        
                    //std::cout << "Filling (" << j + 1 << ") elem " << i << " with " << cands[0] << '\n';
                    //filled = true;
                }
                if (cands.size() == 0) {
                    if (bDisp) {
                        apply_indent(indent_level);
                        std::cerr << "No candidates for element " << elemIdx << ".\n";
                    }
                    return -1;
                }
                else {
                    //std::cout << "HEHEHE\n";
                    // TODO: Speculative filling of a candidate leading to problem in a certain block
                    //std::cout << "Cands size: " << cands.size();
                    //std::cout << "Candidates: ";
                    //for (auto& c : cands)
                    //    std::cout << c << ", ";
                    //std::cout << '\n';
                    std::vector<int> cands_to_remove;
                    std::map<int, int> candidate_to_problematic_area;
                    for (auto& c : cands) {
                        // TODO:
                        zadanie[elemIdx] = c;
                        bool found = false;
                        for (int areaIdx = 0; areaIdx < Area.size(); areaIdx++)
                            if (!is_possible_to_fill_elem_into_area(c, areaIdx, zadanie, Area, InverseMap)) {
                                found = true;
                                candidate_to_problematic_area.insert(std::pair<int, int>(c, areaIdx));
                                break;
                            }
                        if (found)
                            cands_to_remove.push_back(c);

                        zadanie[elemIdx] = 0;
                    }

                    for (auto e : cands_to_remove) {
                        auto it = std::find(cands.begin(), cands.end(), e);
                        cands.erase(it);
                    }

                    if (cands.size() == 1) {
                        sfe.push_back(std::pair<int, int>{elemIdx, cands[0]});
                        //zadanie[i] = cands[0];
                        //no_filled--;
                        //e_f++;
                        if (bDisp) {
                            apply_indent(indent_level);
                            
                            std::cerr << " SFN: " << elemIdx << " -> " << cands[0];
                            std::cerr << " (Orig. candidates: ";
                            std::cerr << cands[0];
                            for (auto e : cands_to_remove) {
                                std::cerr << ", " << e << "(" << candidate_to_problematic_area[e] << ")";
                            }
                            std::cerr << ")\n";
                        }
                    }
                }
            }
        }

        //finds elements that are fillable uniquely within certain area
        std::vector<std::pair<int, int>> sfa;
        for (int ii = 0; ii < Area.size(); ii++) {
            auto res = can_be_uniquely_filled_in_area(ii, zadanie, Area, InverseMap);
            for (auto &e : res) {
                if (bDisp) {
                    apply_indent(indent_level);
                    std::cerr << " SFA: (" << ii << "): " << e.first << " -> " << e.second << '\n';
                }
                //zadanie[e.first] = e.second;
                //no_filled--;
                sfa.push_back(e);
                //e_f++;
                //filled = true;
            }
        }
        // fill into zadanie
        for (auto &e : sfe) {
            // check if we do not have
            // mismatched solution candidates
            if (zadanie[e.first] != 0) {
                if (zadanie[e.first] != e.second) {
                    if (bDisp) {
                        apply_indent(indent_level);
                        std::cerr << "Mismatch: element " << e.first << " two candidates: " << e.second << ", " << zadanie[e.first] << ".\n";
                    }
                    return -1;
                }
                
            }
            else {
                zadanie[e.first] = e.second;
                filled_indices.push_back(e.first);
                if (bDisp) {
                    apply_indent(indent_level);
                    std::cerr << "Adding element " << e.first << " -> " << e.second << '\n';
                }
                e_f++;
                filled = true;
            }
        }
        for (auto &e : sfa) {
            // check if we do not have
            // mismatched solution candidates
            if (zadanie[e.first] != 0) {
                if (zadanie[e.first] != e.second) {
                    if (bDisp) {
                        apply_indent(indent_level);
                        std::cerr << "Mismatch: element " << e.first << " two candidates: " << e.second << ", " << zadanie[e.first] << ".\n";
                    }
                    return -1;
                }
                
            }
            else {
                zadanie[e.first] = e.second;
                e_f++;
                filled_indices.push_back(e.first);
                if (bDisp) {
                    apply_indent(indent_level);
                    std::cerr << "Adding element " << e.first << " -> " << e.second << '\n';
                }
                filled = true;
            }
        }
        j++;
    }
    return e_f;
}

//struct Element_displayer
//{
//    virtual void display_element(std::ostream& os, int e) = 0;
//};
//
//struct Standard_displayer: Element_displayer
//{
//    std_header* std_head;
//    virtual void display_element(std::ostream& os, int e);
//};

void disp_sudoku_element(std_header &std_head, int elemIdx) {
    int cur_idx = 0;
    for (int rr = 0; rr < std_head.rowsize; rr++ ) {
        for (int cc = 0; cc < std_head.colsize; cc++) {
            if (cur_idx == elemIdx)
                std::cout << ".";
            else
                std::cout << "x";
            cur_idx++;
        }
        std::cout << '\n';
    }
}

void disp_sudoku_area(std_header& std_head, const std::vector<std::vector<int>> Areas, int areaIdx) {
    int cur_idx = 0;
    std::set<int> area_elements;

    for (auto& e : Areas[areaIdx])
        area_elements.insert(e);

    for (int rr = 0; rr < std_head.rowsize; rr++) {
        for (int cc = 0; cc < std_head.colsize; cc++) {
            if (area_elements.find(cur_idx) != area_elements.end())
                std::cout << "x";
            else
                std::cout << ".";
            cur_idx++;
        }
        std::cout << '\n';
    }
}



void Standard_displayer::display_element(std::ostream& os, int e)
{

    disp_elem3_os(os, e, std_head);
}

void Standard_displayer::display_element_address(std::ostream& os, int adr)
{
    int row = adr / std_head->rowsize;
    int col = adr % std_head->rowsize; // rowsize=colsize
    os << "E(" + std::to_string(row + 1) + "," + std::to_string(col + 1) << ")";
    //disp_elem3_os(os, e, std_head);
}


int SolveSudoku2_ED(int zadanie_size, int* zadanie, const std::vector<std::vector<int>>& Area, const std::map<int, std::vector<int>>& InverseMap, std::vector<int>& filled_indices, Element_displayer& ed, int indent_level = 0, bool bDisp = true) {
    int e_f = 0;
    bool filled = true;
    int j = 0;
    while (filled) {
        if (bDisp) {
            apply_indent(indent_level);
            std::cerr << "Iteration " << j + 1 << ": \n";
        }
        filled = false;

        // find elements which are uniquely fillable as 
        // intersection of blocks
        std::vector<std::pair<int, int>> sfe;
        for (int elemIdx = 0; elemIdx < zadanie_size; elemIdx++) {
            if (zadanie[elemIdx] == 0) {
                auto cands = get_candidates(elemIdx, zadanie, Area, InverseMap);
                if (cands.size() == 1) {
                    sfe.push_back(std::pair<int, int>{elemIdx, cands[0]});
                    //zadanie[i] = cands[0];
                    //no_filled--;
                    //e_f++;
                    if (bDisp) {
                        apply_indent(indent_level);
                        //std::cerr << " SFE: " << elemIdx << " -> " << cands[0] << '\n';
                        std::cerr << " SFE: " << elemIdx << " -> ";
                        ed.display_element(std::cerr, cands[0]);
                        std::cerr << '\n';
                    }

                    //std::cout << "Filling (" << j + 1 << ") elem " << i << " with " << cands[0] << '\n';
                    //filled = true;
                }
                else if (cands.size() == 0) {
                    if (bDisp) {
                        apply_indent(indent_level);
                        std::cerr << "No candidates for element " << elemIdx << ".\n";
                    }
                    return -1;
                }
                else {
                    //std::cout << "HEHEHE\n";
                    // TODO: Speculative filling of a candidate leading to problem in a certain block
                    //std::cout << "Cands size: " << cands.size();
                    //std::cout << "Candidates: ";
                    //for (auto& c : cands)
                    //    std::cout << c << ", ";
                    //std::cout << '\n';
                    std::vector<int> cands_to_remove;
                    std::map<int, int> candidate_to_problematic_area;
                    for (auto& c : cands) {
                        // TODO:
                        zadanie[elemIdx] = c;
                        bool found = false;
                        for (int areaIdx = 0; areaIdx < Area.size(); areaIdx++)
                            if (!is_possible_to_fill_elem_into_area(c, areaIdx, zadanie, Area, InverseMap)) {
                                found = true;
                                candidate_to_problematic_area.insert(std::pair<int, int>(c, areaIdx));
                                break;
                            }
                        if (found)
                            cands_to_remove.push_back(c);

                        zadanie[elemIdx] = 0;
                    }

                    for (auto e : cands_to_remove) {
                        auto it = std::find(cands.begin(), cands.end(), e);
                        cands.erase(it);
                    }

                    if (cands.size() == 1) {
                        sfe.push_back(std::pair<int, int>{elemIdx, cands[0]});
                        //zadanie[i] = cands[0];
                        //no_filled--;
                        //e_f++;
                        if (bDisp) {
                            apply_indent(indent_level);
                            //std::cerr << " SFE: " << elemIdx << " -> " << cands[0] << '\n';
                            std::cerr << " SFN: " << elemIdx << " -> ";
                            ed.display_element(std::cerr, cands[0]);
                            std::cerr << " (Orig. candidates: ";
                            std::cerr << cands[0];
                            for (auto e : cands_to_remove) {
                                std::cerr << ", " << e << "(" << candidate_to_problematic_area[e] << ")";
                            }
                            std::cerr << ")\n";
                        }
                    }
                }
            }
		}

            //finds elements that are fillable uniquely within certain area
            std::vector<std::pair<int, int>> sfa;
            for (int ii = 0; ii < Area.size(); ii++) {
                auto res = can_be_uniquely_filled_in_area(ii, zadanie, Area, InverseMap);
                for (auto& e : res) {
                    if (bDisp) {
                        apply_indent(indent_level);
                        //std::cerr << " SFA: (" << ii << "): " << e.first << " -> " << e.second << '\n';
                        std::cerr << " SFA: (" << ii << "): " << e.first << " -> ";
                        ed.display_element(std::cerr, e.second);
                        std::cerr << '\n';
                    }
                    //zadanie[e.first] = e.second;
                    //no_filled--;
                    sfa.push_back(e);
                    //e_f++;
                    //filled = true;
                }
            }
            // fill into zadanie
            for (auto& e : sfe) {
                // check if we do not have
                // mismatched solution candidates
                if (zadanie[e.first] != 0) {
                    if (zadanie[e.first] != e.second) {
                        if (bDisp) {
                            apply_indent(indent_level);
                            std::cerr << "Mismatch: element " << e.first << " two candidates: ";
                            ed.display_element(std::cerr, e.second);
                            std::cerr << ", ";
                            ed.display_element(std::cerr, zadanie[e.first]);
                            std::cerr << ".\n";
                        }
                        return -1;
                    }

                }
                else {
                    zadanie[e.first] = e.second;
                    filled_indices.push_back(e.first);
                    if (bDisp) {
                        apply_indent(indent_level);
                        std::cerr << " Adding element " << e.first << " -> ";
                        ed.display_element(std::cerr, e.second);
                        std::cerr << '\n';
                    }
                    e_f++;
                    filled = true;
                }
            }
            for (auto& e : sfa) {
                // check if we do not have
                // mismatched solution candidates
                if (zadanie[e.first] != 0) {
                    if (zadanie[e.first] != e.second) {
                        if (bDisp) {
                            apply_indent(indent_level);
                            //std::cerr << "Mismatch: element " << e.first << " two candidates: " << e.second << ", " << zadanie[e.first] << ".\n";
                            std::cerr << "Mismatch: element " << e.first << " two candidates: ";
                            ed.display_element(std::cerr, e.second);
                            std::cerr << ", ";
                            ed.display_element(std::cerr, zadanie[e.first]);
                            std::cerr << ".\n";
                        }
                        return -1;
                    }

                }
                else {
                    zadanie[e.first] = e.second;
                    e_f++;
                    if (bDisp) {
                        apply_indent(indent_level);
                        std::cerr << " Adding element " << e.first << " -> ";
                        ed.display_element(std::cerr, e.second);
                        std::cerr << '\n';
                    }
                    filled_indices.push_back(e.first);
                    filled = true;
                }
            }
            j++;
        }
        return e_f;
    }

int SolveSudoku2_ED_AD(int zadanie_size, int* zadanie, const std::vector<std::vector<int>>& Areas, const std::vector<std::string> &Area_txt_descs, const std::map<int, std::vector<int>>& InverseMap, std::vector<int>& filled_indices, Element_displayer& ed, int indent_level = 0, bool bDisp = true) {
    int e_f = 0;
    bool filled = true;
    int j = 0;
    while (filled) {
        if (bDisp) {
            apply_indent(indent_level);
            std::cerr << "Iteration " << j + 1 << ": \n";
        }
        filled = false;

        // find elements which are uniquely fillable as 
        // intersection of blocks
        std::vector<std::pair<int, int>> sfe;
        for (int elemIdx = 0; elemIdx < zadanie_size; elemIdx++) {
            if (zadanie[elemIdx] == 0) {
                auto cands = get_candidates(elemIdx, zadanie, Areas, InverseMap);
                if (cands.size() == 1) {
                    sfe.push_back(std::pair<int, int>{elemIdx, cands[0]});
                    //zadanie[i] = cands[0];
                    //no_filled--;
                    //e_f++;
                    if (bDisp) {
                        apply_indent(indent_level);
                        //std::cerr << " SFE: " << elemIdx << " -> " << cands[0] << '\n';
                        //std::cerr << " SFE: " << elemIdx << " -> ";
                        std::cerr << " SFE: ";
                        ed.display_element_address(std::cerr, elemIdx);
                        std::cerr << " -> ";
                        ed.display_element(std::cerr, cands[0]);
                        std::cerr << '\n';
                    }

                    //std::cout << "Filling (" << j + 1 << ") elem " << i << " with " << cands[0] << '\n';
                    //filled = true;
                }
                else if (cands.size() == 0) {
                    if (bDisp) {
                        apply_indent(indent_level);
                        std::cerr << "No candidates for element " << elemIdx << ".\n";
                    }
                    return -1;
                }
                else {
                    //std::cout << "HEHEHE\n";
                    // TODO: Speculative filling of a candidate leading to problem in a certain block
                    //std::cout << "Cands size: " << cands.size();
                    //std::cout << "Candidates: ";
                    //for (auto& c : cands)
                    //    std::cout << c << ", ";
                    //std::cout << '\n';
                    std::vector<int> cands_to_remove;
                    std::map<int, int> candidate_to_problematic_area;
                    for (auto& c : cands) {
                        // TODO:
                        zadanie[elemIdx] = c;
                        bool found = false;
                        for (int areaIdx = 0; areaIdx < Areas.size(); areaIdx++)
                            if (!is_possible_to_fill_elem_into_area(c, areaIdx, zadanie, Areas, InverseMap)) {
                                found = true;
                                candidate_to_problematic_area.insert(std::pair<int, int>(c, areaIdx));
                                break;
                            }
                        if (found)
                            cands_to_remove.push_back(c);

                        zadanie[elemIdx] = 0;
                    }

                    for (auto e : cands_to_remove) {
                        auto it = std::find(cands.begin(), cands.end(), e);
                        cands.erase(it);
                    }

                    if (cands.size() == 1) {
                        sfe.push_back(std::pair<int, int>{elemIdx, cands[0]});
                        //zadanie[i] = cands[0];
                        //no_filled--;
                        //e_f++;
                        if (bDisp) {
                            apply_indent(indent_level);
                            //std::cerr << " SFN: " << elemIdx << " -> ";
                            std::cerr << " SFN: ";
                            ed.display_element_address(std::cerr, elemIdx);
                            std::cerr << " -> ";
                            ed.display_element(std::cerr, cands[0]);
                            std::cerr << " (Orig. candidates: ";
                            std::cerr << cands[0];
                            for (auto e : cands_to_remove) {
                                std::cerr << ", " << e << "(" << Area_txt_descs[candidate_to_problematic_area[e]] << ")";
                            }
                            std::cerr << ")\n";
                        }
                    }
                }
            }
		}

            //finds elements that are fillable uniquely within certain area
            std::vector<std::pair<int, int>> sfa;
            for (int ii = 0; ii < Areas.size(); ii++) {
                auto res = can_be_uniquely_filled_in_area(ii, zadanie, Areas, InverseMap);
                for (auto& e : res) {
                    if (bDisp) {
                        apply_indent(indent_level);
                        //std::cerr << " SFA: (" << ii << "): " << e.first << " -> " << e.second << '\n';
                        std::cerr << " SFA: (" << Area_txt_descs[ii] << "): ";
                        ed.display_element_address(std::cerr, e.first);
                        std::cerr << " -> ";
                        ed.display_element(std::cerr, e.second);
                        std::cerr << '\n';
                    }
                    //zadanie[e.first] = e.second;
                    //no_filled--;
                    sfa.push_back(e);
                    //e_f++;
                    //filled = true;
                }
            }
            // fill into zadanie
            for (auto& e : sfe) {
                // check if we do not have
                // mismatched solution candidates
                if (zadanie[e.first] != 0) {
                    if (zadanie[e.first] != e.second) {
                        if (bDisp) {
                            apply_indent(indent_level);
                            std::cerr << "Mismatch: element ";
                            ed.display_element_address(std::cerr, e.first);
                            std::cerr << " two candidates: ";
                            ed.display_element(std::cerr, e.second);
                            std::cerr << ", ";
                            ed.display_element(std::cerr, zadanie[e.first]);
                            std::cerr << ".\n";
                        }
                        return -1;
                    }

                }
                else {
                    zadanie[e.first] = e.second;
                    filled_indices.push_back(e.first);
                    if (bDisp) {
                        apply_indent(indent_level);
                        std::cerr << " Adding element ";
                        ed.display_element_address(std::cerr, e.first);
                        std::cerr << " -> ";
                        ed.display_element(std::cerr, e.second);
                        std::cerr << '\n';
                    }
                    e_f++;
                    filled = true;
                }
            }
            for (auto& e : sfa) {
                // check if we do not have
                // mismatched solution candidates
                if (zadanie[e.first] != 0) {
                    if (zadanie[e.first] != e.second) {
                        if (bDisp) {
                            apply_indent(indent_level);
                            //std::cerr << "Mismatch: element " << e.first << " two candidates: " << e.second << ", " << zadanie[e.first] << ".\n";
                            std::cerr << "Mismatch: element ";
                            ed.display_element_address(std::cerr, e.first);
                            std::cerr << " two candidates: ";
                            ed.display_element(std::cerr, e.second);
                            std::cerr << ", ";
                            ed.display_element(std::cerr, zadanie[e.first]);
                            std::cerr << ".\n";
                        }
                        return -1;
                    }

                }
                else {
                    zadanie[e.first] = e.second;
                    e_f++;
                    if (bDisp) {
                        apply_indent(indent_level);
                        std::cerr << " Adding element ";
                        ed.display_element_address(std::cerr, e.first);
                        std::cerr << " -> ";
                        ed.display_element(std::cerr, e.second);
                        std::cerr << '\n';
                    }
                    filled_indices.push_back(e.first);
                    filled = true;
                }
            }
            j++;
        }
        return e_f;
    }

/* Memory-wise solution: keeps track of candidates for any unfilled element */
int SolveSudoku2_ED_AD2(int zadanie_size, int* zadanie, const std::vector<std::vector<int>>& Areas, const std::vector<std::string>& Area_txt_descs, const std::map<int, std::vector<int>>& InverseMap, std::vector<int>& filled_indices, Element_displayer& ed, int indent_level = 0, bool bDisp = true) {
    int e_f = 0;
    bool filled = true;
    int j = 0;

    std::map<int, std::set<int>> candidates;
    init_candidates(zadanie_size, zadanie, Areas, InverseMap, candidates);
    // disp_candidates(candidates);
        
    while (filled) {
        filled = false;
        // Eliminate cross candidates
        /*
         * zzzxxxzzz
         *    yyy
         *    yyy
         *  if there are candidates which are present only in xxx part then they can be remove from z and y parts
         */
        for (int i = 0; i < Areas.size(); i++)
            for (int j = 0; j < Areas.size(); j++)
                if (i != j) {
                    auto s = get_blocks_intersection(i, j, Areas);
                    if (s.size()) {
                        //std::cout << i << ", " << j << " = " << s.size() << '\n';

                        // exists candidate c in s, which is not in bi - s
                        // eliminate it from bj - s
                        // and vice-versa

                        std::set<int> set_s_u_cands{};
                        for (int e : s)
                            if (zadanie[e] == 0)
                                for (auto c : candidates[e])
                                    set_s_u_cands.insert(c);

                        std::set<int> cands_bi_s{};
                        for (int e : Areas[i]) {
                            if (zadanie[e] == 0 && s.find(e) == s.end()) {
                                for (int el : candidates[e])
                                    cands_bi_s.insert(el);
                            }
                        }
                        std::set<int> diff{};
                        std::set_difference(set_s_u_cands.begin(), set_s_u_cands.end(),
                            cands_bi_s.begin(), cands_bi_s.end(), std::inserter(diff, diff.end()));

                        for (int e : Areas[j]) {
                            if (zadanie[e] == 0 && s.find(e) == s.end()) {
                                for (int d : diff)
                                    if (candidates[e].find(d) != candidates[e].end()) {
                                        candidates[e].erase(d);
                                        filled = true;
                                        std::cerr << "Removing candidate " << d
                                            << " from candidates for element ";
                                        ed.display_element_address(std::cerr, e);
                                        std::cerr << " as cross-blocks ";
                                        std::cerr << Area_txt_descs[i] << " and " << Area_txt_descs[j] << ".\n";
                                    }
                            }
                        }

                        //vice-versa
                        std::set<int> cands_bj_s{};
                        for (int e : Areas[j]) {
                            if (zadanie[e] == 0 && s.find(e) == s.end()) {
                                for (int el : candidates[e])
                                    cands_bj_s.insert(el);
                            }
                        }
                        std::set<int> diffj{};
                        std::set_difference(set_s_u_cands.begin(), set_s_u_cands.end(), cands_bi_s.begin(), cands_bi_s.end(), std::inserter(diffj, diffj.end()));

                        for (int e : Areas[i]) {
                            if (zadanie[e] == 0 && s.find(e) == s.end()) {
                                for (int d : diffj)
                                    if (candidates[e].find(d) != candidates[e].end()) {
                                        candidates[e].erase(d);
                                        filled = true;
                                        std::cerr << "Removing candidate " << d
                                            << " from candidates for elemend = ";
                                        ed.display_element_address(std::cerr, e);
                                        std::cerr << " as cross-blocks " << Area_txt_descs[i] << " and " << Area_txt_descs[j] << ".\n";
                                    }
                            }
                        }
                    }
                }



        if (bDisp) {
            apply_indent(indent_level);
            std::cerr << "Iteration " << j + 1 << ": \n";
        }
        //filled = false;

        // find elements which are uniquely fillable as 
        // intersection of blocks
        std::vector<std::pair<int, int>> sfe;
        for (int elemIdx = 0; elemIdx < zadanie_size; elemIdx++) {
            if (zadanie[elemIdx] == 0) {
                //auto cands = get_candidates(elemIdx, zadanie, Areas, InverseMap);
                auto cands = candidates[elemIdx];
                if (cands.size() == 1) {
                    sfe.push_back(std::pair<int, int>{elemIdx, *cands.begin()});
                    //zadanie[i] = cands[0];
                    //no_filled--;
                    //e_f++;
                    if (bDisp) {
                        apply_indent(indent_level);
                        //std::cerr << " SFE: " << elemIdx << " -> " << cands[0] << '\n';
                        //std::cerr << " SFE: " << elemIdx << " -> ";
                        std::cerr << " SFE: ";
                        ed.display_element_address(std::cerr, elemIdx);
                        std::cerr << " -> ";
                        ed.display_element(std::cerr, *cands.begin());
                        std::cerr << '\n';
                    }

                    //std::cout << "Filling (" << j + 1 << ") elem " << i << " with " << cands[0] << '\n';
                    //filled = true;
                }
                else if (cands.size() == 0) {
                    if (bDisp) {
                        apply_indent(indent_level);
                        std::cerr << "No candidates for element " << elemIdx << ".\n";
                    }
                    return -1;
                }
                else {
                    //std::cout << "HEHEHE\n";
                    // TODO: Speculative filling of a candidate leading to problem in a certain block
                    //std::cout << "Cands size: " << cands.size();
                    //std::cout << "Candidates: ";
                    //for (auto& c : cands)
                    //    std::cout << c << ", ";
                    //std::cout << '\n';
                    std::vector<int> cands_to_remove;
                    std::map<int, int> candidate_to_problematic_area;
                    for (auto& c : cands) {
                        // TODO:
                        zadanie[elemIdx] = c;
                        bool found = false;
                        for (int areaIdx = 0; areaIdx < Areas.size(); areaIdx++)
                            if (!is_possible_to_fill_elem_into_area(c, areaIdx, zadanie, Areas, InverseMap)) {
                                found = true;
                                candidate_to_problematic_area.insert(std::pair<int, int>(c, areaIdx));
                                break;
                            }
                        if (found) {
                            cands_to_remove.push_back(c);
                            std::cerr << "Eliminating candidate " << c << " for the element ";
                            ed.display_element_address(std::cerr, elemIdx);
                            std::cerr << " due to area " << Area_txt_descs[candidate_to_problematic_area[c]] << ".\n";
                        }

                        zadanie[elemIdx] = 0;
                    }

                    for (auto e : cands_to_remove) {
                        auto it = std::find(cands.begin(), cands.end(), e);
                        cands.erase(it);
                        candidates[elemIdx].erase(e);
                    }

                    if (cands.size() == 1) {
                        sfe.push_back(std::pair<int, int>{elemIdx, *cands.begin()});
                        //zadanie[i] = cands[0];
                        //no_filled--;
                        //e_f++;
                        if (bDisp) {
                            apply_indent(indent_level);
                            //std::cerr << " SFN: " << elemIdx << " -> ";
                            std::cerr << " SFN: ";
                            ed.display_element_address(std::cerr, elemIdx);
                            std::cerr << " -> ";
                            ed.display_element(std::cerr, *cands.begin());
                            std::cerr << " (Orig. candidates: ";
                            std::cerr << *cands.begin();
                            for (auto e : cands_to_remove) {
                                std::cerr << ", " << e << "(" << Area_txt_descs[candidate_to_problematic_area[e]] << ")";
                            }
                            std::cerr << ")\n";
                        }
                    }
                }
            }
        }

        //finds elements that are fillable uniquely within certain area
        std::vector<std::pair<int, int>> sfa;
        for (int ii = 0; ii < Areas.size(); ii++) {
            auto res = can_be_uniquely_filled_in_area2(ii, zadanie, candidates, Areas, InverseMap);
            for (auto& e : res) {
                if (bDisp) {
                    apply_indent(indent_level);
                    //std::cerr << " SFA: (" << ii << "): " << e.first << " -> " << e.second << '\n';
                    std::cerr << " SFA: (" << Area_txt_descs[ii] << "): ";
                    ed.display_element_address(std::cerr, e.first);
                    std::cerr << " -> ";
                    ed.display_element(std::cerr, e.second);
                    std::cerr << '\n';
                    //for (int elemIdx : Areas[ii]) {
                    //    std::cout << elemIdx << ": ";
                    //    debug_show_set(candidates[elemIdx]);
                    //}
                }
                //zadanie[e.first] = e.second;
                //no_filled--;
                sfa.push_back(e);
                //e_f++;
                //filled = true;
            }
        }
        // fill into zadanie
        for (auto& e : sfe) {
            // check if we do not have
            // mismatched solution candidates
            if (zadanie[e.first] != 0) {
                if (zadanie[e.first] != e.second) {
                    if (bDisp) {
                        apply_indent(indent_level);
                        std::cerr << "Mismatch: element ";
                        ed.display_element_address(std::cerr, e.first);
                        std::cerr << " two candidates: ";
                        ed.display_element(std::cerr, e.second);
                        std::cerr << ", ";
                        ed.display_element(std::cerr, zadanie[e.first]);
                        std::cerr << ".\n";
                    }
                    return -1;
                }

            }
            else {
                zadanie[e.first] = e.second;
                filled_indices.push_back(e.first);
                for (auto AreaIdx: InverseMap.at(e.first))
                    for (auto elemIdx: Areas[AreaIdx])
                        if (zadanie[elemIdx] == 0) {
                            candidates[elemIdx].erase(e.second);
                        }
                candidates[e.first].clear();
                if (bDisp) {
                    apply_indent(indent_level);
                    std::cerr << " Adding element ";
                    ed.display_element_address(std::cerr, e.first);
                    std::cerr << " -> ";
                    ed.display_element(std::cerr, e.second);
                    std::cerr << '\n';
                }
                e_f++;
                filled = true;
            }
        }
        for (auto& e : sfa) {
            // check if we do not have
            // mismatched solution candidates
            if (zadanie[e.first] != 0) {
                if (zadanie[e.first] != e.second) {
                    if (bDisp) {
                        apply_indent(indent_level);
                        //std::cerr << "Mismatch: element " << e.first << " two candidates: " << e.second << ", " << zadanie[e.first] << ".\n";
                        std::cerr << "Mismatch: element ";
                        ed.display_element_address(std::cerr, e.first);
                        std::cerr << " two candidates: ";
                        ed.display_element(std::cerr, e.second);
                        std::cerr << ", ";
                        ed.display_element(std::cerr, zadanie[e.first]);
                        std::cerr << ".\n";
                    }
                    return -1;
                }

            }
            else {
                zadanie[e.first] = e.second;
                e_f++;
                if (bDisp) {
                    apply_indent(indent_level);
                    std::cerr << " Adding element ";
                    ed.display_element_address(std::cerr, e.first);
                    std::cerr << " -> ";
                    ed.display_element(std::cerr, e.second);
                    std::cerr << '\n';
                }
                filled_indices.push_back(e.first);
                for (auto AreaIdx : InverseMap.at(e.first))
                    for (auto elemIdx : Areas[AreaIdx])
                        if (zadanie[elemIdx] == 0) {
                            candidates[elemIdx].erase(e.second);
                        }
                candidates[e.first].clear();
                filled = true;
            }
        }
        j++;
    }
    return e_f;
}



#if 0
    // Finds all uniquely solveable elements
    int SolveSudoku2n(int zadanie_size, int* zadanie,
        std::vector<std::vector<int>>&Areas, std::map<int, std::vector<int>>&InverseMap,
        std::vector<int>&filled_indices) {
        int e_f = 0;
        bool filled = true;
        int j = 0;
        while (filled) {
            //std::cerr << "Iteration " << j + 1 << ": \n";
            filled = false;

            // find elements which are uniquely fillable as 
            // intersection of blocks
            std::vector<std::pair<int, int>> sfe;
            for (int i = 0; i < zadanie_size; i++) {
                if (zadanie[i] == 0) {
                    auto cands = get_candidates(i, zadanie, Areas, InverseMap, false);
                    if (cands.size() == 1) {
                        sfe.push_back(std::pair<int, int>{i, cands[0]});
                        //zadanie[i] = cands[0];
                        //no_filled--;
                        //e_f++;
                        //std::cerr << "SFE: " << i << " -> " << cands[0] << '\n';
                        //std::cout << "Filling (" << j + 1 << ") elem " << i << " with " << cands[0] << '\n';
                        //filled = true;
                    }
                    if (cands.size() == 0) {
                        //std::cerr << "Something wrong.\n";
                        return -1;
                    }
                }
            }

            //finds elements that are fillable uniquely within certain area
            std::vector<std::pair<int, int>> sfa;
            for (int ii = 0; ii < Areas.size(); ii++) {
                auto res = can_be_uniquely_filled_in_area(ii, zadanie, Areas, InverseMap);
                for (auto e : res) {
                    //std::cerr << "SFA: (" << ii << "): " << e.first << " -> " << e.second << '\n';
                    //zadanie[e.first] = e.second;
                    //no_filled--;
                    sfa.push_back(e);
                    //e_f++;
                    //filled = true;
                }
            }
            // fill into zadanie
            for (auto e : sfe) {
                // check if we do not have
                // mismatched solution candidates
                if (zadanie[e.first] != 0) {
                    if (zadanie[e.first] != e.second) {
                        //std::cerr << "Mismatch: element " << e.first << " two candidates: " << e.second << ", " << zadanie[e.first] << ".\n";
                        return -1;
                    }

                }
                else {
                    zadanie[e.first] = e.second;
                    filled_indices.push_back(e.first);
                    e_f++;
                    filled = true;
                }
            }
            for (auto e : sfa) {
                // check if we do not have
                // mismatched solution candidates
                if (zadanie[e.first] != 0) {
                    if (zadanie[e.first] != e.second) {
                        //std::cerr << "Mismatch: element " << e.first << " two candidates: " << e.second << ", " << zadanie[e.first] << ".\n";
                        return -1;
                    }

                }
                else {
                    zadanie[e.first] = e.second;
                    e_f++;
                    filled_indices.push_back(e.first);
                    filled = true;
                }
            }
            j++;
        }
        return e_f;
    }
}

    // Finds all uniquely solveable elements
    int SolveSudoku2n2(int zadanie_size, int* zadanie,
        std::vector<std::vector<int>>&Areas, std::map<int, std::vector<int>>&InverseMap,
        std::vector<int>&filled_indices) {
        int e_f = 0;
        bool filled = true;
        int j = 0;
        while (filled) {
            //std::cerr << "Iteration " << j + 1 << ": \n";
            filled = false;

            // find elements which are uniquely fillable as 
            // intersection of blocks
            std::vector<std::pair<int, int>> sfe;
            for (int i = 0; i < zadanie_size; i++) {
                if (zadanie[i] == 0) {
                    auto cands = get_candidates(i, zadanie, Areas, InverseMap, false);
                    if (cands.size() == 1) {
                        sfe.push_back(std::pair<int, int>{i, cands[0]});
                        //zadanie[i] = cands[0];
                        //no_filled--;
                        //e_f++;
                        //std::cerr << "SFE: " << i << " -> " << cands[0] << '\n';
                        //std::cout << "Filling (" << j + 1 << ") elem " << i << " with " << cands[0] << '\n';
                        //filled = true;
                    }
                    if (cands.size() == 0) {
                        //std::cerr << "Something wrong.\n";
                        return -1;
                    }
                }
            }

            //finds elements that are fillable uniquely within certain area
            std::vector<std::pair<int, int>> sfa;
            for (int ii = 0; ii < Areas.size(); ii++) {
                auto res = can_be_uniquely_filled_in_area(ii, zadanie, Areas, InverseMap);
                for (auto e : res) {
                    //std::cerr << "SFA: (" << ii << "): " << e.first << " -> " << e.second << '\n';
                    //zadanie[e.first] = e.second;
                    //no_filled--;
                    sfa.push_back(e);
                    //e_f++;
                    //filled = true;
                }
            }
            // fill into zadanie
            for (auto e : sfe) {
                // check if we do not have
                // mismatched solution candidates
                if (zadanie[e.first] != 0) {
                    if (zadanie[e.first] != e.second) {
                        //std::cerr << "Mismatch: element " << e.first << " two candidates: " << e.second << ", " << zadanie[e.first] << ".\n";
                        return -1;
                    }

                }
                else {
                    zadanie[e.first] = e.second;
                    filled_indices.push_back(e.first);
                    e_f++;
                    filled = true;
                }
            }
            for (auto e : sfa) {
                // check if we do not have
                // mismatched solution candidates
                if (zadanie[e.first] != 0) {
                    if (zadanie[e.first] != e.second) {
                        //std::cerr << "Mismatch: element " << e.first << " two candidates: " << e.second << ", " << zadanie[e.first] << ".\n";
                        return -1;
                    }

                }
                else {
                    zadanie[e.first] = e.second;
                    e_f++;
                    filled_indices.push_back(e.first);
                    filled = true;
                }
            }
            j++;
        }
        return e_f;
    }

#endif

int SolveSudoku(int zadanie_size, int *zadanie, std::vector<std::vector<int>> &Area, std::map<int, std::vector<int>> &InverseMap) {
    int e_f = 0;
    bool filled = true;
    int j = 0;
    while (filled) {
        std::cerr << "Iteration " << j + 1 << ": \n";
        filled = false;
        for (int i = 0; i < zadanie_size; i++) {
            if (zadanie[i] == 0) {
                auto cands = get_candidates(i, zadanie, Area, InverseMap);
                if (cands.size() == 1) {
                    zadanie[i] = cands[0];
                    //no_filled--;
                    e_f++;
                    std::cerr << i << " -> " << cands[0] << '\n';
                    //std::cout << "Filling (" << j + 1 << ") elem " << i << " with " << cands[0] << '\n';
                    filled = true;
                }
                if (cands.size() == 0) {
                    std::cerr << "Something wrong.\n";
                }
            }
        }

        for (int ii = 0; ii < Area.size(); ii++) {
            auto res = can_be_uniquely_filled_in_area(ii, zadanie, Area, InverseMap);
            for (auto &e : res) {
                std::cerr << e.first << " -> " << e.second << '\n';
                zadanie[e.first] = e.second;
                //no_filled--;
                e_f++;
                filled = true;
            }
        }
        j++;
    }
    return e_f;
}

bool TestSolution(int* zadanie, const std::vector<std::vector<int>>& Areas) {
    if (Areas.size()) {
        const int area_len = static_cast<int>(Areas[0].size());
        for (auto &a : Areas) {
            std::vector<int> filled_elements;
            for (int i = 0; i < area_len; i++)
                filled_elements.push_back(0);
            //int filled_elements[] = { 0,0,0,0,0,0,0,0,0 };
            for (auto e : a) {
                int z = zadanie[e];
                if (z == 0)
                    return false; // incomplete
                // assumes z != 0
                if (filled_elements[z - 1] != 0)
                    return false; // more than one number in the area
                else
                    filled_elements[z - 1]++;
            }
        }
    }
    return true;
}

void apply_indent(int level) {
    for (int i = 0; i < level; i++)
        std::cerr << " ";
}
void SolveSudoku3_with_recursion(int elements_to_fill, 
    int zadanie_size, int* zadanie, 
    std::vector<std::vector<int>>& Area, std::map<int, std::vector<int>>& InverseMap,
    int indent_level, void (disp(int*,...)), ... ) {
    //std::cout << "Recursion to fill: " << elements_to_fill << '\n';
    va_list args;
    va_start(args, disp);
    int va_cnt = va_arg(args, int);
    void* va_ppp = nullptr;
    if (va_cnt > 0) {
        va_ppp = va_arg(args, void*);
    }
    va_end(args);
    
    

    if (elements_to_fill == 0) {
        //std::cout << "HEHEHEHE - SOOSOS\n";
        if (TestSolution(zadanie, Area)) {
            // print solution
            
            std::cout << "=================Solution:\n";
            disp(zadanie, va_cnt, va_ppp);
            
        }
    }
    else {
        // Select element with minimal possibilities to select
        //std::vector<std::vector<int>> cands_vec;
        int minimal_size = 1000; // assuming areas are shorter than 1000
        int minimal_index = -1;
        for (int i = 0; i < zadanie_size; i++) {
            if (zadanie[i] == 0) {
                auto cands = get_candidates(i, zadanie, Area, InverseMap, false);
                // std::cout << "DEBUG: ";
                // disp_vec(cands);
                // std::cout << '\n';
                if (cands.size()) {
                    //cands_vec.push_back(cands);

                    if (minimal_size > cands.size()) {
                        minimal_size = (int)cands.size();
                        minimal_index = i;
                    }
                }
                else {
                    //std::cout << "HERE\n";
                    minimal_index = -1;
                    break;
                }
            }

        }
        if (minimal_index == -1) {
            return;
        }
        
        auto cands = get_candidates(minimal_index, zadanie, Area, InverseMap, false);
        /*std::cout << "Minimal size: " << minimal_size << '\n';
        std::cout << "Minimal index: " << minimal_index << '\n';
        std::cout << "Possibilities: ";
        disp_vec(cands);*/
       
        for (auto c : cands) {
            std::vector<int> filled_indices{};
            /*std::cout << "BEFORE SOLVE: \n";
            disp(zadanie, va_cnt, va_ppp);
            std::cout << "--------------\n";*/
            zadanie[minimal_index] = c;

            apply_indent(indent_level);
            std::cerr << "Trying to fill: " << minimal_index << " -> " << c << '\n';
            apply_indent(indent_level);
            std::cerr << "(\n";
            //int e_fl = SolveSudoku2n(zadanie_size, zadanie, Area, InverseMap, filled_indices);
            int e_fl = SolveSudoku2(zadanie_size, zadanie, Area, InverseMap, filled_indices, indent_level/*, false*/);
            /*for (int i = 0; i < subpath.size(); i++)
                std::cout << '\t';
            std::cout << "Candidate: " << minimal_index << " -> " << c << '\n';*/
            /*for (int i = 0; i < subpath.size(); i++)
                std::cout << '\t';
            std::cout << "Result: " << e_fl << '\n';*/
            
            apply_indent(indent_level);
            std::cerr << "Temporaly filled: " << e_fl << '\n';
            
            /*std::cout << "AFTER SOLVE: \n";
            disp(zadanie, va_cnt, va_ppp);
            std::cout << "--------------\n";*/
            
            if (e_fl == -1) {
                //std::cout << "HEREUUUU\n";
                //std::cout << "Filled indices size: " << filled_indices.size() << '\n';
            }
            else {
                int t_f = elements_to_fill - e_fl - 1;
                
                SolveSudoku3_with_recursion(t_f, zadanie_size, zadanie, Area, InverseMap, indent_level + 1, disp, va_cnt, va_ppp);
                
                
            }
            
            // unfill filled indices
            apply_indent(indent_level);
            std::cerr << "Unfilling: " << minimal_index << " -> " << c << '\n';
            apply_indent(indent_level);
            std::cerr << ")\n";
            zadanie[minimal_index] = 0;
            for (auto i : filled_indices)
                zadanie[i] = 0;
            /*std::cout << "AFTER CLEAR: \n";
            
            disp(zadanie, va_cnt, va_ppp);
            std::cout << "--------------\n";*/
        }
    }
}

void SolveSudoku3_with_recursion_ED(int elements_to_fill,
    int zadanie_size, int* zadanie,
    const std::vector<std::vector<int>>& Area, const std::map<int, std::vector<int>>& InverseMap,
    Element_displayer &ed, 
    int indent_level, void(disp(int*, ...)), ...) {
    //std::cout << "Recursion to fill: " << elements_to_fill << '\n';
    va_list args;
    va_start(args, disp);
    int va_cnt = va_arg(args, int);
    void* va_ppp = nullptr;
    if (va_cnt > 0) {
        va_ppp = va_arg(args, void*);
    }
    va_end(args);

    if (elements_to_fill == 0) {
        //std::cout << "HEHEHEHE - SOOSOS\n";
        if (TestSolution(zadanie, Area)) {
            // print solution

            std::cout << "=================Solution:\n";
            disp(zadanie, va_cnt, va_ppp);

        }
    }
    else {
        // Select element with minimal possibilities to select
        //std::vector<std::vector<int>> cands_vec;
        int minimal_size = 1000; // assuming areas are shorter than 1000
        int minimal_index = -1;
        for (int i = 0; i < zadanie_size; i++) {
            if (zadanie[i] == 0) {
                auto cands = get_candidates(i, zadanie, Area, InverseMap, false);
                // std::cout << "DEBUG: ";
                // disp_vec(cands);
                // std::cout << '\n';
                if (cands.size()) {
                    //cands_vec.push_back(cands);

                    if (minimal_size > cands.size()) {
                        minimal_size = (int)cands.size();
                        minimal_index = i;
                    }
                }
                else {
                    //std::cout << "HERE\n";
                    minimal_index = -1;
                    break;
                }
            }

        }
        if (minimal_index == -1) {
            return;
        }

        auto cands = get_candidates(minimal_index, zadanie, Area, InverseMap, false);
        /*std::cout << "Minimal size: " << minimal_size << '\n';
        std::cout << "Minimal index: " << minimal_index << '\n';
        std::cout << "Possibilities: ";
        disp_vec(cands);*/

        for (auto c : cands) {
            std::vector<int> filled_indices{};
            /*std::cout << "BEFORE SOLVE: \n";
            disp(zadanie, va_cnt, va_ppp);
            std::cout << "--------------\n";*/
            zadanie[minimal_index] = c;

            apply_indent(indent_level);
            //std::cerr << "Trying to fill: " << minimal_index << " -> " << c << '\n';
            std::cerr << "Trying to fill: " << minimal_index << " -> ";
            ed.display_element(std::cerr, c);
            std::cerr << '\n';
            apply_indent(indent_level);
            std::cerr << "(\n";
            //int e_fl = SolveSudoku2n(zadanie_size, zadanie, Area, InverseMap, filled_indices);
            int e_fl = SolveSudoku2_ED(zadanie_size, zadanie, Area, InverseMap, filled_indices, ed, indent_level/*, false*/);
            /*for (int i = 0; i < subpath.size(); i++)
                std::cout << '\t';
            std::cout << "Candidate: " << minimal_index << " -> " << c << '\n';*/
            /*for (int i = 0; i < subpath.size(); i++)
                std::cout << '\t';
            std::cout << "Result: " << e_fl << '\n';*/

            apply_indent(indent_level);
            std::cerr << "Temporaly filled: " << e_fl << '\n';

            /*std::cout << "AFTER SOLVE: \n";
            disp(zadanie, va_cnt, va_ppp);
            std::cout << "--------------\n";*/

            if (e_fl == -1) {
                //std::cout << "HEREUUUU\n";
                //std::cout << "Filled indices size: " << filled_indices.size() << '\n';
            }
            else {
                int t_f = elements_to_fill - e_fl - 1;

                SolveSudoku3_with_recursion_ED(t_f, zadanie_size, zadanie, Area, InverseMap, ed, indent_level + 1, disp, va_cnt, va_ppp);


            }

            // unfill filled indices
            apply_indent(indent_level);
            //std::cerr << "Unfilling: " << minimal_index << " -> " << c << '\n';
            std::cerr << "Unfilling: " << minimal_index << " -> ";
            ed.display_element(std::cerr, c);
            std::cerr << '\n';
            apply_indent(indent_level);
            std::cerr << ")\n";
            zadanie[minimal_index] = 0;
            for (auto i : filled_indices)
                zadanie[i] = 0;
            /*std::cout << "AFTER CLEAR: \n";

            disp(zadanie, va_cnt, va_ppp);
            std::cout << "--------------\n";*/
        }
    }
}



void disp_elem(int e) {
    if (e)
        std::cout << e;
    else
        std::cout << '.';
}

void disp_elem2(int e, const content_type sdk_type, int width) {
    if (e) {
        if (sdk_type == content_type::NUMBERS) {
            std::cout << std::setw(width) << e;
            if (width > 1)
                std::cout << " ";
        } 
        else if (sdk_type == content_type::LETTERS) {
            std::vector<int> base26{};

            int pom_e = e - 1;
            
            do {
                int digit = pom_e % 26;
                base26.push_back(digit);
                pom_e /= 26;
            } while (pom_e > 0);
                      
            for (int i = 0; i < width - base26.size(); i++)
                std::cout << " ";

            while (!base26.empty()) {
                int v = base26.back();

                std::cout << (char)('A' + v);
                base26.pop_back();
            }
            
            if (width > 1)
                std::cout << " ";
        }
        else {
            std::cout << e;
        }
    }
    else
        std::cout << std::setw(width) << '.';
}

void disp_elem3(int e, const std_header *std_head/*, int width*/) {
    if (e) {
        if (std_head->cnt_type == content_type::NUMBERS) {
            std::cout << std::setw(std_head->max_width) << e;
            if (std_head->max_width > 1)
                std::cout << " ";
        }
        else if (std_head->cnt_type == content_type::LETTERS) {
            std::vector<int> base26{};

            int pom_e = e - 1;

            do {
                int digit = pom_e % 26;
                base26.push_back(digit);
                pom_e /= 26;
            } while (pom_e > 0);

            for (int i = 0; i < std_head->max_width - base26.size(); i++)
                std::cout << " ";

            while (!base26.empty()) {
                int v = base26.back();

                std::cout << (char)('A' + v);
                base26.pop_back();
            }

            if (std_head->max_width > 1)
                std::cout << " ";
        }
        else if (std_head->cnt_type == content_type::MAPPED_LETTERS) {
            std::string val;
            auto it = std_head->int_to_ascii_mapping.find(e);
            if (it == std_head->int_to_ascii_mapping.end())
                if (std_head->b_single_letter)
                    std::cout << std::setw(std_head->max_width) << '.';
                else
                    std::cout << std::setw(std_head->max_width + 1) << '.';
            else {
                if (std_head->b_single_letter)
                    std::cout << std::setw(std_head->max_width) << it->second;
                else
                    std::cout << std::setw(std_head->max_width + 1) << it->second;
            }

            if (std_head->max_width > 1)
                std::cout << " ";
        }
        else {
            std::cout << e;
        }
    }
    else
        if (std_head->b_single_letter)
            std::cout << std::setw(std_head->max_width) << '.';
        else
            std::cout << std::setw(std_head->max_width+1) << '.';
}

void disp_elem3_os(std::ostream &os, int e, const std_header* std_head/*, int width*/) {
    if (e) {
        if (std_head->cnt_type == content_type::NUMBERS) {
            os << std::setw(std_head->max_width) << e;
            if (std_head->max_width > 1)
                os << " ";
        }
        else if (std_head->cnt_type == content_type::LETTERS) {
            std::vector<int> base26{};

            int pom_e = e - 1;

            do {
                int digit = pom_e % 26;
                base26.push_back(digit);
                pom_e /= 26;
            } while (pom_e > 0);

            for (int i = 0; i < std_head->max_width - base26.size(); i++)
                os << " ";

            while (!base26.empty()) {
                int v = base26.back();

                std::cout << (char)('A' + v);
                base26.pop_back();
            }

            if (std_head->max_width > 1)
                os << " ";
        }
        else if (std_head->cnt_type == content_type::MAPPED_LETTERS) {
            std::string val;
            auto it = std_head->int_to_ascii_mapping.find(e);
            if (it == std_head->int_to_ascii_mapping.end())
                if (std_head->b_single_letter)
                    os << std::setw(std_head->max_width) << '.';
                else
                    os << std::setw(std_head->max_width + 1) << '.';
            else {
                if (std_head->b_single_letter)
                    os << std::setw(std_head->max_width) << it->second;
                else
                    os << std::setw(std_head->max_width + 1) << it->second;
            }

            if (std_head->max_width > 1)
                os << " ";
        }
        else {
            os << e;
        }
    }
    else
        if (std_head->b_single_letter)
            std::cout << std::setw(std_head->max_width) << '.';
        else
            std::cout << std::setw(std_head->max_width + 1) << '.';
}



void disp_SAM(int* zadanie, ...) {
    int offset = 0;
    for (int c = 0; c < 6; c++) {
        for (int i = 0; i < 9; i++)
            disp_elem(zadanie[offset + i]);
        offset += 9;
        std::cout << "   ";
        for (int i = 0; i < 9; i++)
            disp_elem(zadanie[offset + i]);
        offset += 9;
        std::cout << '\n';
    }
    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < 21; i++)
            disp_elem(zadanie[offset + i]);
        std::cout << '\n';
        offset += 21;
    }

    for (int c = 0; c < 3; c++) {
        std::cout << "      ";
        for (int i = 0; i < 9; i++)
            disp_elem(zadanie[offset + i]);
        std::cout << '\n';
        offset += 9;
    }
    
    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < 21; i++)
            disp_elem(zadanie[offset + i]);
        std::cout << '\n';
        offset += 21;
    }
    for (int c = 0; c < 6; c++) {
        for (int i = 0; i < 9; i++)
            disp_elem(zadanie[offset + i]);
        offset += 9;
        std::cout << "   ";
        for (int i = 0; i < 9; i++)
            disp_elem(zadanie[offset + i]);
        offset += 9;
        std::cout << '\n';
    }
}

//enum class content_type
//{
//    NUMBERS,
//    LETTERS
//};

void skip_ws(char*& pom) {
    while (*pom && (*pom == ' ' || *pom == '\t'))
        pom++;
}

/* reads string representation of a positive integer */
bool read_num(char*& pom, int& res_v, bool single_digit = false) {
    skip_ws(pom);
    if (!pom || *pom < '0' || *pom > '9') {
        std::cerr << "Expecting digit.";
        if (pom && *pom) {
            std::cerr << " Found '" << *pom << "'.\n";
        }
        return false;
    }
    int v = 0;
    while (*pom && *pom >= '0' && *pom <= '9') {
        v = 10 * v + (int)(*pom - '0');
        pom++;
        if (single_digit) {
            res_v = v;
            return true;
        }
    }
    res_v = v;
    return true;
}


/* . - empty character */
int get_value(char*&pom, content_type sdk_type, bool single_value = true) {
    skip_ws(pom);
    if (single_value) {
        switch (sdk_type) {
        case content_type::NUMBERS:
            if (*pom == '.') {
                pom++;
                return 0;
            }
            else {
                if (*pom >= '1' && *pom <= '9') {
                    int value = 0;
                    while (*pom >= '0' && *pom <= '9') {
                        value = 10 * value + (int)(*pom - '0');
                        pom++;
                        if (single_value)
                            return value;
                    }
                    return value;
                }
                else {
                    std::cerr << "Unknown character '" << *pom << "'. Expecting numbers 1-9." << std::endl;
                    return -1;
                }
            }
            break;
        case content_type::LETTERS:
            if (*pom == '.') {
                pom++;
                return 0;
            }
            else if (*pom >= 'A' && *pom <= 'Z') {
                int value = 0;
                while (*pom >= 'A' && *pom <= 'Z') {
                    value = 26 * value  + (int)(*pom - 'A') + 1;
                    pom++;
                    if (single_value)
                        return value;
                }
                return value;
            }
            else {
                std::cerr << "Unknown character '" << *pom << "'. Expecting letters A-Z." << std::endl;
                return -1;
            }            
            break;
        default:
            std::cerr << "Unknown content type." << std::endl;
            return -1;
            break;
        };
    }
    else {
        switch (sdk_type) {
        case content_type::NUMBERS:
            if (*pom == '.') {
                pom++;
                return 0;
            }
            else if (*pom >= '1' && *pom <= '9') {
                int value = 0;
                while (*pom >= '0' && *pom <= '9') {
                    value = 10 * value + (int)(*pom - '0');
                    pom++;
                }
                return value;
            }
            else {
                std::cerr << "Unknown character '" << *pom << "'. Expecting numbers 1-9." << std::endl;
                return -1;
            }
            break;
        case content_type::LETTERS:
            if (*pom == '.') {
                pom++;
                return 0;
            }
            else if (*pom >= 'A' && *pom <= 'Z') {
                int value = 0;
                // Allows to form AA, AB, ... combinations
                while (*pom >= 'A' && *pom <= 'Z') {
                    value = 26 * value + (int)(*pom - 'A') + 1;
                    pom++;
                }
                return value;
            }
            else {
                std::cerr << "Unknown character '" << *pom << "'. Expecting letters A-Z." << std::endl;
                return -1;
            }
            break;
        default:
            std::cerr << "Unknown content type." << std::endl;
            return -1;
            break;
        };
    }
}

bool parse_std_header(char* header, std_header& std_head) {

    char* pom = header;

    //std::cout << "\n DEBUG: " << header << "\n";

    skip_ws(pom);
    /* read cc */
    int cc = 0;
    bool b_cc = read_num(pom, cc);
    if (!b_cc) {
        std::cerr << "Expecting numerical cc value in a block.\n";
        return false;
    }

    if (cc <= 0) {
        std::cerr << "Value cc must be positive integer. Got " << cc << " instead.\n";
        return false;
    }
    
    std_head.cc = cc;
   
    skip_ws(pom);
    /* read rc */
    int rc = 0;
    bool b_rc = read_num(pom, rc);

    if (!b_rc) {
        std::cerr << "Expecting numerical rc value in a block.\n";
        return false;
    }

    if (rc <= 0) {
        std::cerr << "Value rc must be positive integer. Got " << rc << " instead.\n";
        return false;
    }

    std_head.rc = rc;

    skip_ws(pom);

    /* read cnt_type */
    if (*pom != 'A' && *pom != 'N' && *pom != 'M') {
        std::cerr << "Unknown cnt_type value - [ A | N | M ].\n";
        return false;
    }
    else {
        if (*pom == 'A')
            std_head.cnt_type = content_type::LETTERS;
        else if (*pom == 'N')
            std_head.cnt_type = content_type::NUMBERS;
        else
            std_head.cnt_type = content_type::MAPPED_LETTERS;

        pom++;
    }

    skip_ws(pom);
    /* read diag */
    if (*pom != 'S' && *pom != 'D') {
        std::cerr << "Unknown sudoku value - [ S | D ].\n";
        return false;
    }
    else {
        if (*pom == 'S')
            std_head.diagonal = false;
        else
            std_head.diagonal = true;

        pom++;
    }
    std_head.colsize = std_head.rowsize = rc * cc;
    skip_ws(pom);
    /* For mapped letters read the mapping, comma separated strings */
    if (std_head.cnt_type == content_type::MAPPED_LETTERS) {
        int num_read_mappings = 0;
        int max_length = 0;
        while (*pom && num_read_mappings < std_head.colsize) {
            skip_ws(pom);
            //char buffer[10];
            char* pom_from = pom;
            char* pom_to;
            while (*pom && *pom != ',') {
                pom_to = pom;
                pom++;
            }
            num_read_mappings++;
            int cur_length = pom_to - pom_from + 1;
            std::string key(pom_from, cur_length);
            if (cur_length > max_length)
                max_length = cur_length;
            std_head.ascii_to_int_mapping.insert(std::pair <std::string, int>(key, num_read_mappings));
            std_head.int_to_ascii_mapping.insert(std::pair <int, std::string>(num_read_mappings, key));
            if (num_read_mappings < std_head.colsize)
                if (*pom == ',')
                    pom++;
                else {
                    std::cerr << "Missing delimiter ',' of mappings\n";
                    return false;
                }
        }
        std::cout << "Read mappings count: " << num_read_mappings << '\n';
    
        for (auto& val : std_head.ascii_to_int_mapping) {
            std::cout << "K:'" << val.first << "', V:" << val.second << '\n';
        }

        for (auto& val : std_head.int_to_ascii_mapping) {
            std::cout << "K:'" << val.first << "', V:" << val.second << '\n';
        }

        if (num_read_mappings < std_head.colsize) {
            std::cerr << "Insuficient mapping present: " << num_read_mappings << " / " << std_head.colsize << "\n";
            return false;
        }

        if (max_length > 1) {
            std_head.b_single_letter = false;
            std_head.max_width = max_length;
        }
        else {
            std_head.b_single_letter = true;
            std_head.max_width = 1;
        }
    }
    else if (std_head.cnt_type == content_type::NUMBERS) {
        if (std_head.colsize > 9) {
            std_head.b_single_letter = false;
            std_head.max_width = 2; // TODO: log_10 + 1
        }
        else {
            std_head.b_single_letter = true;
            std_head.max_width = 1;
        }
    }
    else if (std_head.cnt_type == content_type::LETTERS) {
        if (std_head.colsize > 26) {
            std_head.b_single_letter = false;
            std_head.max_width = 2; // TODO: log_26 + 1
        }
        else {
            std_head.b_single_letter = true;
            std_head.max_width = 1;
        }
    }

    return true;
}

void dump_reg_header(const reg_header& reg_head) {
    std::cout << "RC: " << reg_head.rc << '\n';
    std::cout << "CC: " << reg_head.cc << '\n';
    std::cout << "Rows: " << reg_head.rowsize << '\n';
    std::cout << "Columns: " << reg_head.colsize << '\n';
    std::cout << "Content type (num): " << (int)reg_head.cnt_type << '\n';
    std::cout << "Content type (txt): " << txt_content_type[(size_t)reg_head.cnt_type] << '\n';
    std::cout << "Diagonal: " << (reg_head.diagonal?"Yes":"No") << '\n';
    std::cout << "Region type (num): " << (int)reg_head.reg_type << '\n';
    std::cout << "Region type (txt): " << txt_reg_type[(size_t)reg_head.reg_type] << '\n';
    if (reg_head.reg_type == t_reg_type::T_IF || reg_head.reg_type == t_reg_type::T_EF) {
        std::cout << "File internal: " << reg_head.internal << '\n';
        if (reg_head.reg_type == t_reg_type::T_EF)
            std::cout << "Filename (external): " << reg_head.reg_ext_filename << '\n';
    }
}

bool parse_reg_header(char* header, reg_header& reg_head) {

    char* pom = header;

    //std::cout << "\n DEBUG: " << header << "\n";

    skip_ws(pom);
    /* read cc */
    int cc = 0;
    bool b_cc = read_num(pom, cc);
    if (!b_cc) {
        std::cerr << "Expecting numerical cc value in a block.\n";
        return false;
    }

    if (cc <= 0) {
        std::cerr << "Value cc must be positive integer. Got " << cc << " instead.\n";
        return false;
    }

    reg_head.cc = cc;

    skip_ws(pom);

    /* read rc */
    int rc = 0;
    bool b_rc = read_num(pom, rc);

    if (!b_rc) {
        std::cerr << "Expecting numerical rc value in a block.\n";
        return false;
    }

    if (rc <= 0) {
        std::cerr << "Value rc must be positive integer. Got " << rc << " instead.\n";
        return false;
    }

    reg_head.rc = rc;

    skip_ws(pom);
    /* read sdk_type */
    if (*pom != 'A' && *pom != 'N') {
        std::cerr << "Unknown sdk_type value - [ A | N ].\n";
        return false;
    }
    else {
        if (*pom == 'A')
            reg_head.cnt_type = content_type::LETTERS;
        else
            reg_head.cnt_type = content_type::NUMBERS;

        pom++;
    }
    /* read diag */
    skip_ws(pom);
    if (*pom != 'S' && *pom != 'D') {
        std::cerr << "Unknown sudoku value - [ S | D ].\n";
        return false;
    }
    else {
        if (*pom == 'S')
            reg_head.diagonal = false;
        else
            reg_head.diagonal = true;

        pom++;
    }
    
    skip_ws(pom);
    /* get region type */
    if (!*pom) {
        std::cerr << "Missing region sudoku type.\n";
        return false;
    }
    if (*pom != 'T') {
        std::cerr << "Region sudoku type must start with T.\n";
        return false;
    }
    else {
        if (!strncmp("T8", pom, 2)) {
            reg_head.reg_type = t_reg_type::T8;
            pom += 2;
        } 
        else if (!strncmp("T9-15", pom, 5)) {
            reg_head.reg_type = t_reg_type::T9_15;
            pom += 5;
        }
        else if (!strncmp("T9-17", pom, 5)) {
            reg_head.reg_type = t_reg_type::T9_17;
            pom += 5;
        }
        else if (!strncmp("T9", pom, 2)) {
            reg_head.reg_type = t_reg_type::T9;
            pom += 2;
        }
        else if (!strncmp("TN", pom, 2)) {
            reg_head.reg_type = t_reg_type::TN;
            pom += 2;
        }
        else if (!strncmp("TR", pom, 2)) {
            reg_head.reg_type = t_reg_type::T_IF;
            reg_head.internal = true;
            pom += 2;
        }
        else if (!strncmp("TF", pom, 2)) {
            reg_head.reg_type = t_reg_type::T_EF;
            reg_head.internal = false;
            pom += 2;
            skip_ws(pom);
            std::cout << "ROW: " << pom << '\n';
            /* get filename */
            char buf[1024];
            sscanf(pom, "%s", buf);

            //std::cout << "aa" "bb";

            if (strlen(buf) == 0) {
                std::cerr << "Expection region type filename.\n";
                return false;
            }
            reg_head.reg_ext_filename = buf;
        }
        else {
            std::cerr << "Unknown region sudoku type. Expecting:\n"
                << "\tTR: for reading from file interval(default)\n"
                << "\tT8: for standard Pravda 8x8 sudoku\n"
                << "\tT9: for standard Pravda 9x9 sudoku\n"
                << "\tT9-15: for standard Pravda 9x9 sudoku in year 2015\n"
                << "\tT9-17: for standard Pravda 9x9 sudoku in year 2017\n"
                << "\tTN: for no regions (just rows, cols and optionally diagonals with D type)\n"
                << "\tTF <region_file>: for reading region data from external file\n\n";
            return false;
        }
    }

    reg_head.colsize = reg_head.rowsize = rc * cc;
    
    if (reg_head.cnt_type == content_type::NUMBERS) {
        if (reg_head.colsize > 9) {
            reg_head.b_single_letter = false;
            reg_head.max_width = 2; // TODO: log_10 + 1
        }
        else {
            reg_head.b_single_letter = true;
            reg_head.max_width = 1;
        }
    }
    else if (reg_head.cnt_type == content_type::LETTERS) {
        if (reg_head.colsize > 26) {
            reg_head.b_single_letter = false;
            reg_head.max_width = 2; // TODO: log_26 + 1
        }
        else {
            reg_head.b_single_letter = true;
            reg_head.max_width = 1;
        }
    }

    /* DEBUG */
    dump_reg_header(reg_head);

    return true;
}

bool read_content_sudoku_mapped(std::ifstream& infile, const std::vector<int>& expected_sizes, const std_header &std_head, int* zadanie) {
    char buffer[512];
    int idx = 0; // read element
    int intcol = 0, introw = 0;
    int maxrow = static_cast<int>(expected_sizes.size());

    if (!infile.good()) {
        std::cerr << "File is not open." << std::endl;
        infile.close();
        return false;
    }

    do {
        infile.getline(buffer, 512);
        if (infile.good()) {
            char* pom = buffer;

            while (*pom && introw < maxrow && intcol < expected_sizes[introw]) {
                //skipws
                while (*pom && (*pom == ' ' || *pom == '\t')) pom++;
                if (*pom == '#') {
                    // skip the rest of the line
                    *pom = '\0';
                }
                else {
                    if (std_head.b_single_letter) {
                        int value = -1;
                        if (*pom == '.')
                            value = 0;
                        else {
                            const std::string key(pom, 1);
                            //std::map<std::string, int>::iterator it;
                            auto it = std_head.ascii_to_int_mapping.find(key);
                            if (it == std_head.ascii_to_int_mapping.end()) {
                                std::cerr << "Unexpected letter found '" << *pom << "'.\n";
                                return false;
                            }
                            else {
                                value = it->second;
                            }
                        }

                        zadanie[idx++] = value;
                    }
                    else {
                        //std::cout << "'" << pom << "'\n";
                        skip_ws(pom);
                        char* from = pom;
                        char* to;
                        while (*pom && *pom != ' ') {
                            to = pom;
                            pom++;
                        }
                        int value = -1;
                        if (*from == '.')
                            value = 0;
                        else {
                            const std::string key(from, to - from + 1);
                            //std::map<std::string, int>::iterator it;
                            auto it = std_head.ascii_to_int_mapping.find(key);
                            if (it == std_head.ascii_to_int_mapping.end()) {
                                std::cerr << "Unexpected sequence found '" << *pom << "'.\n";
                                return false;
                            }
                            else {
                                value = it->second;
                                
                            }
                        }
                        zadanie[idx++] = value;

                        // TODO: 
                    }
                    pom++;
                    intcol++;
                }
            }

            if (intcol != expected_sizes[introw]) {
                /*std::cerr << "Insufficient number digits on the line." << std::endl;
                std::cerr << buffer << std::endl;
                infile.close();
                return false;*/
            }
            else {
                intcol = 0;
                introw++;
            }
        }

    } while (infile.good() && introw < maxrow);

    std::cout << "ROWS: " << introw << '\n';
    if (introw != maxrow) {
        std::cerr << "Not enough rows." << std::endl;
        infile.close();
        return false;
    }

    return true;
}



bool read_content_sudoku(std::ifstream& infile, const std::vector<int>& expected_sizes, content_type sdk_type, bool single_value, int maxvalue, int* zadanie) {
    char buffer[512];
    int idx = 0; // read element
    int intcol = 0, introw = 0;
    int maxrow = static_cast<int>(expected_sizes.size());

    if (!infile.good()) {
        std::cerr << "File is not open." << std::endl;
        infile.close();
        return false;
    }

    do {
        infile.getline(buffer, 512);
        if (infile.good()) {
            char* pom = buffer;

            while (*pom && introw < maxrow && intcol < expected_sizes[introw]) {
                //skipws
                while (*pom && (*pom == ' ' || *pom == '\t')) pom++;
                if (*pom == '#') {
                    // skip the rest of the line
                    *pom = '\0';
                }
                else {
                    int res = -1;
                    if ((res = get_value(pom, sdk_type, single_value)) >= 0) {
                        if (res <= maxvalue) {
                            zadanie[idx++] = res;
                            intcol++;
                        }
                        else {
                            // error
                        }
                    }
                }
            }
            if (intcol != expected_sizes[introw]) {
                /*std::cerr << "Insufficient number digits on the line." << std::endl;
                std::cerr << buffer << std::endl;
                infile.close();
                return false;*/
            }
            else {
                intcol = 0;
                introw++;
            }
        }

    } while (infile.good() && introw < maxrow);

    if (introw != maxrow) {
        std::cerr << "Not enough rows." << std::endl;
        infile.close();
        return false;
    }

    return true;
}

bool read_content_sudoku_vec(std::ifstream& infile, const std::vector<int>& expected_sizes, content_type sdk_type, bool single_value, int maxvalue, std::vector<int> &zadanie) {
    char buffer[512];
    int idx = 0; // read element
    int intcol = 0, introw = 0;
    int maxrow = static_cast<int>(expected_sizes.size());

    if (!infile.good()) {
        std::cerr << "File is not open." << std::endl;
        infile.close();
        return false;
    }

    do {
        infile.getline(buffer, 512);
        if (infile.good()) {
            char* pom = buffer;

            while (*pom && introw < maxrow && intcol < expected_sizes[introw]) {
                //skipws
                while (*pom && (*pom == ' ' || *pom == '\t')) pom++;
                if (*pom == '#') {
                    // skip the rest of the line
                    *pom = '\0';
                }
                else {
                    int res = -1;
                    if ((res = get_value(pom, sdk_type, single_value)) >= 0) {
                        if (res <= maxvalue) {
                            zadanie[idx++] = res;
                            intcol++;
                        }
                        else {
                            // error
                        }
                    }
                }
            }
            if (intcol != expected_sizes[introw]) {
                /*std::cerr << "Insufficient number digits on the line." << std::endl;
                std::cerr << buffer << std::endl;
                infile.close();
                return false;*/
            }
            else {
                intcol = 0;
                introw++;
            }
        }

    } while (infile.good() && introw < maxrow);

    if (introw != maxrow) {
        std::cerr << "Not enough rows." << std::endl;
        infile.close();
        return false;
    }

    return true;
}

const std::vector<int> expected_SAM_sizes{ 18, 18, 18, 18, 18, 18, 21, 21, 21,  9,  9,  9, 21, 21, 21, 18, 18, 18, 18, 18, 18 };

bool read_SAM_sudoku(std::ifstream& infile, int* zadanie) {
    return read_content_sudoku(infile, expected_SAM_sizes, content_type::NUMBERS, true, 9, zadanie);
}

bool read_SAM_sudoku_vec(std::ifstream& infile, std::vector<int>& zadanie) {
    return read_content_sudoku_vec(infile, expected_SAM_sizes, content_type::NUMBERS, true, 9, zadanie);
}


bool read_SAM_sudokuOLD(const char* filename, int (&zadanie)[369]) {

    constexpr int expected_sizes[21] = { 18, 18, 18, 18, 18, 18, 21,
                                 21, 21,  9,  9,  9, 21, 21,
                                 21, 18, 18, 18, 18, 18, 18 };
    std::ifstream infile;
    infile.open(filename, std::ifstream::in);
    char buffer[512];
    int idx = 0; // read element

    if (!infile.good()) {
        std::cerr << "Error opening file \"" << filename << "\"." << std::endl;
        infile.close();
        return false;
    }

    int intcol = 0, introw = 0;

    do {
        infile.getline(buffer, 512);
        if (infile.good()) {
            char* pom = buffer;

            while (*pom && introw < 21 && intcol < expected_sizes[introw]) {
                while (*pom && (*pom == ' ' || *pom == '\t')) pom++;
                //skipws
               /* if (*pom == '#')
                    continue;*/
                int value = 0;
                if ((*pom >= '1' && *pom <= '9') || *pom == '.') {

                    if (*pom == '.')
                        value = 0;
                    else
                        value = *pom - '0';

                    zadanie[idx++] = value;
                   /* switch (expected_sizes[introw])
                    {
                    case 18:
                        if (intcol >= 9)
                            setfield(intcol + 3, introw, value);
                        else
                            setfield(intcol, introw, value);
                        break;
                    case 9:
                        setfield(intcol + 6, introw, value);
                        break;
                    default:
                        setfield(intcol, introw, value);
                    };*/

                    intcol++;
                    pom++;
                }
                else {
                    std::cerr << "Unknown character '" << *pom << "'." << std::endl;
                    infile.close();
                    return false;
                }
            }
            if (intcol != expected_sizes[introw]) {
                std::cerr << "Insufficient number digits on the line." << std::endl;
                std::cerr << buffer << std::endl;
                infile.close();
                return false;
            }

            intcol = 0;
            introw++;
        }

    } while (infile.good() && introw < 21);

    if (introw != 21) {
        std::cerr << "Not enough rows." << std::endl;
        infile.close();
        return false;
    }
    infile.close();
    return true;
}


void disp_STDBareD(int* zadanie, ...) {
    std::va_list args;
    va_start(args, zadanie);

    int siz = va_arg(args, int);
    va_end(args);

    for (int i = 0; i < siz; i++) {
        for (int j = 0; j < siz; j++) {
            int idx = siz * i + j;
            disp_elem2(zadanie[idx], content_type::NUMBERS, 1);
        }
        std::cout << '\n';
    }
}

void disp_3x3(int* zadanie, ...) {
    std::va_list args;
    va_start(args, zadanie);

    int *cnt = va_arg(args, int*);
    //std::cout << cnt << ": CNT";
    if (cnt != 0) {
        //std::cout << "EUEUE\n";
        std_header* head = (std_header *)va_arg(args, void*);
        //std::cout << head << ": HEAD\n";
        //std::cout << head->rowsize << ": ROWSIZE\n";
        //std::cout << head->colsize << ": COLSIZE\n";
        for (int i = 0; i <head->rowsize; i++) {
            for (int j = 0; j <head->colsize; j++) {
                int idx = head->colsize * i + j;
                //disp_elem2(zadanie[idx], head->cnt_type, 1);
                disp_elem3(zadanie[idx], head/*, 1*/);
            }
            std::cout << "\n";
        }
    }
    else {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int idx = 9 * i + j;
                disp_elem(zadanie[idx]);
            }
            std::cout << "\n";
        }
    }
    va_end(args);
}

std::set<int> get_blocks_intersection(int blockIdx1, int blockIdx2, const std::vector<std::vector<int>>& Areas) {
    std::set<int> b1, b2, out;
    for (auto e : Areas[blockIdx1])
        b1.insert(e);
    for (auto e : Areas[blockIdx2])
        b2.insert(e);

    std::set_intersection(b1.begin(), b1.end(), b2.begin(), b2.end(), std::inserter(out, out.end()));
    return out;
}

void Solve(int zadanie_size, int *zadanie, std::vector<std::vector<int>> &Area, std::map<int, std::vector<int>> &InverseMap, void (disp(int *, ...)), ...) { 
    /*std::va_list args,args2;
    va_start(args, disp);
    va_copy(args2, args);
    int cnt = va_arg(args2, int);
    if (cnt != 0) {
        void* ppp = va_arg(args2, void*);
        vprintf("AA:%d - %p\n", args);
        printf("BB:%d - %p\n", cnt, ppp);
        disp(zadanie, cnt, ppp);
    }
    else {
        disp(zadanie, cnt);
    }
    va_end(args2);
    va_end(args);
    return;*/

    /* parse variable arguments 
     expected options: 
        0 | unused pointer |
     or
        1 pointer_to_header
    */
    std::va_list args;
    va_start(args, disp);
    int va_cnt = va_arg(args, int);
    void* va_ppp = nullptr;
    if (va_cnt > 0) {
        va_ppp = va_arg(args, void*);
    }
    va_end(args);

    int t_f = count_filled(zadanie_size, zadanie);
    std::vector<int> filled_elements;
    //std::vector<std::pair<int,int>> subpath;
    int e_f = SolveSudoku2(zadanie_size, zadanie, Area, InverseMap, filled_elements);
    std::cerr << "Uniquely fillable: " << e_f << '\n';
    if (e_f != -1) {
        std::cerr << "To fill: " << t_f << "\n";
        std::cerr << "Filled: " << e_f << '\n';
        
        if (t_f != e_f) {
            SolveSudoku3_with_recursion(t_f - e_f,  zadanie_size, zadanie, Area, InverseMap, 1, disp, va_cnt, va_ppp);
            
            /*std::cout << "HHHHEEEE\n";*/
        }
        else {
            // print solution
            std::cout << "=================Solution:\n";
            disp(zadanie, va_cnt, va_ppp);
        }

        //disp(zadanie);
        /*for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int idx = 9 * i + j;
                if (zadanie5[idx])
                    std::cout << zadanie5[idx];
                else std::cout << '.';
            }
            std::cout << "\n";
        }*/
    }
    //va_end(args);
}

void Solve_ED(int zadanie_size, int* zadanie, std::vector<std::vector<int>>& Area, std::map<int, std::vector<int>>& InverseMap, Element_displayer &ed, void(disp(int*, ...)), ...) {
    /*std::va_list args,args2;
    va_start(args, disp);
    va_copy(args2, args);
    int cnt = va_arg(args2, int);
    if (cnt != 0) {
        void* ppp = va_arg(args2, void*);
        vprintf("AA:%d - %p\n", args);
        printf("BB:%d - %p\n", cnt, ppp);
        disp(zadanie, cnt, ppp);
    }
    else {
        disp(zadanie, cnt);
    }
    va_end(args2);
    va_end(args);
    return;*/

    /* parse variable arguments
     expected options:
        0 | unused pointer |
     or
        1 pointer_to_header
    */
    std::va_list args;
    va_start(args, disp);
    int va_cnt = va_arg(args, int);
    void* va_ppp = nullptr;
    if (va_cnt > 0) {
        va_ppp = va_arg(args, void*);
    }
    va_end(args);

    int t_f = count_filled(zadanie_size, zadanie);
    std::vector<int> filled_elements;
    //std::vector<std::pair<int,int>> subpath;
    int e_f = SolveSudoku2_ED(zadanie_size, zadanie, Area, InverseMap, filled_elements, ed);
    std::cerr << "Uniquely fillable: " << e_f << '\n';
    if (e_f != -1) {
        std::cerr << "To fill: " << t_f << "\n";
        std::cerr << "Filled: " << e_f << '\n';

        if (t_f != e_f) {
            std::cout << "------------------\n";
            std::cout << " Before recursion: \n";
            disp(zadanie, va_cnt, va_ppp);
            std::cout << "------------------\n";
            SolveSudoku3_with_recursion_ED(t_f - e_f, zadanie_size, zadanie, Area, InverseMap, ed, 1, disp, va_cnt, va_ppp);

            /*std::cout << "HHHHEEEE\n";*/
        }
        else {
            // print solution
            std::cout << "=================Solution:\n";
            disp(zadanie, va_cnt, va_ppp);
        }

        //disp(zadanie);
        /*for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int idx = 9 * i + j;
                if (zadanie5[idx])
                    std::cout << zadanie5[idx];
                else std::cout << '.';
            }
            std::cout << "\n";
        }*/
    }
    //va_end(args);
}

/* with area txt descriptions */
void Solve_ED_AD(int zadanie_size, int* zadanie, const std::vector<std::vector<int>>& Areas, const std::vector<std::string> &Area_descs, const std::map<int, std::vector<int>>& InverseMap, Element_displayer& ed, void(disp(int*, ...)), ...) {
    /*std::va_list args,args2;
    va_start(args, disp);
    va_copy(args2, args);
    int cnt = va_arg(args2, int);
    if (cnt != 0) {
        void* ppp = va_arg(args2, void*);
        vprintf("AA:%d - %p\n", args);
        printf("BB:%d - %p\n", cnt, ppp);
        disp(zadanie, cnt, ppp);
    }
    else {
        disp(zadanie, cnt);
    }
    va_end(args2);
    va_end(args);
    return;*/

    /* parse variable arguments
     expected options:
        0 | unused pointer |
     or
        1 pointer_to_header
    */
    std::va_list args;
    va_start(args, disp);
    int va_cnt = va_arg(args, int);
    void* va_ppp = nullptr;
    if (va_cnt > 0) {
        va_ppp = va_arg(args, void*);
    }
    va_end(args);

    int t_f = count_filled(zadanie_size, zadanie);
    std::vector<int> filled_elements;
    //std::vector<std::pair<int,int>> subpath;
    int e_f = SolveSudoku2_ED_AD(zadanie_size, zadanie, Areas, Area_descs, InverseMap, filled_elements, ed);
    std::cerr << "Uniquely fillable: " << e_f << '\n';
    if (e_f != -1) {
        std::cerr << "To fill: " << t_f << "\n";
        std::cerr << "Filled: " << e_f << '\n';

        if (t_f != e_f) {
            std::cout << "------------------\n";
            std::cout << " Before recursion: \n";
            disp(zadanie, va_cnt, va_ppp);
            std::cout << "------------------\n";
#if 0
            {
                std::map<int, std::set<int>> candidates;
                for (int i = 0; i < zadanie_size; i++) {
                    if (zadanie[i] == 0) {
                        auto v = get_candidates(i, zadanie, Areas, InverseMap, false);
                        std::set<int> icands{};
                        ed.display_element_address(std::cout, i);
                        std::cout << ": ";
                        for (auto e : v) {
                            icands.insert(e);
                            std::cout << e << ", ";
                        }
                        std::cout << '\n';
                        candidates.insert(std::pair<int, std::set<int>>(i, icands));
                    }
                }
                {
                    for (int i = 0; i < Areas.size(); i++)
                        for (int j = 0; j < Areas.size(); j++)
                            if (i != j) {
                                auto s = get_blocks_intersection(i, j, Areas);
                                std::cout << i << ", " << j << " = " << s.size() << '\n';

                                // exists candidate c in s, which is not in bi - s
                                // eliminate it from bj - s
                                // and vice-versa

                                std::set<int> set_s_u_cands{};
                                for (int e : s)
                                    if (zadanie[e] == 0)
                                        for (auto c : candidates[e])
                                            set_s_u_cands.insert(c);

                                std::set<int> cands_bi_s{};
                                for (int e : Areas[i]) {
                                    if (zadanie[e] == 0 && s.find(e) == s.end()) {
                                        for (int el : candidates[e])
                                            cands_bi_s.insert(el);
                                    }
                                }
                                std::set<int> diff{};
                                std::set_difference(set_s_u_cands.begin(), set_s_u_cands.end(), cands_bi_s.begin(), cands_bi_s.end(), std::inserter(diff, diff.end()));

                                for (int e : Areas[j]) {
                                    if (zadanie[e] == 0 && s.find(e) == s.end()) {
                                        for (int d : diff)
                                            if (candidates[e].find(d) != candidates[e].end()) {
                                                candidates[e].erase(d);
                                                std::cout << "Removed.\n";
                                            }
                                    }
                                }

                                //vice-versa
                                std::set<int> cands_bj_s{};
                                for (int e : Areas[j]) {
                                    if (zadanie[e] == 0 && s.find(e) == s.end()) {
                                        for (int el : candidates[e])
                                            cands_bj_s.insert(el);
                                    }
                                }
                                std::set<int> diffj{};
                                std::set_difference(set_s_u_cands.begin(), set_s_u_cands.end(), cands_bi_s.begin(), cands_bi_s.end(), std::inserter(diffj, diffj.end()));

                                for (int e : Areas[i]) {
                                    if (zadanie[e] == 0 && s.find(e) == s.end()) {
                                        for (int d : diffj)
                                            if (candidates[e].find(d) != candidates[e].end()) {
                                                candidates[e].erase(d);
                                                std::cout << "Removed.\n";
                                            }
                                    }
                                }


                            }

                    for (int i = 0; i < zadanie_size; i++) {
                        if (zadanie[i] == 0) {
                            ed.display_element_address(std::cout, i);
                            std::cout << ": ";

                            for (int e : candidates[i])
                                std::cout << e << ", ";
                            std::cout << '\n';

                        }
                    }

                }

            }
#endif
            SolveSudoku3_with_recursion_ED(t_f - e_f, zadanie_size, zadanie, Areas, InverseMap, ed, 1, disp, va_cnt, va_ppp);

            /*std::cout << "HHHHEEEE\n";*/
        }
        else {
            // print solution
            std::cout << "=================Solution:\n";
            disp(zadanie, va_cnt, va_ppp);
        }

        //disp(zadanie);
        /*for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int idx = 9 * i + j;
                if (zadanie5[idx])
                    std::cout << zadanie5[idx];
                else std::cout << '.';
            }
            std::cout << "\n";
        }*/
    }
    //va_end(args);
}

/* Memory-wise */
void Solve_ED_AD2(int zadanie_size, int* zadanie, const std::vector<std::vector<int>>& Areas, const std::vector<std::string>& Area_descs, const std::map<int, std::vector<int>>& InverseMap, Element_displayer& ed, void(disp(int*, ...)), ...) {
    /*std::va_list args,args2;
    va_start(args, disp);
    va_copy(args2, args);
    int cnt = va_arg(args2, int);
    if (cnt != 0) {
        void* ppp = va_arg(args2, void*);
        vprintf("AA:%d - %p\n", args);
        printf("BB:%d - %p\n", cnt, ppp);
        disp(zadanie, cnt, ppp);
    }
    else {
        disp(zadanie, cnt);
    }
    va_end(args2);
    va_end(args);
    return;*/

    /* parse variable arguments
     expected options:
        0 | unused pointer |
     or
        1 pointer_to_header
    */
    std::va_list args;
    va_start(args, disp);
    int va_cnt = va_arg(args, int);
    void* va_ppp = nullptr;
    if (va_cnt > 0) {
        va_ppp = va_arg(args, void*);
    }
    va_end(args);

    int t_f = count_filled(zadanie_size, zadanie);
    std::vector<int> filled_elements;
    //std::vector<std::pair<int,int>> subpath;
    int e_f = SolveSudoku2_ED_AD2(zadanie_size, zadanie, Areas, Area_descs, InverseMap, filled_elements, ed);
    std::cerr << "Uniquely fillable: " << e_f << '\n';
    if (e_f != -1) {
        std::cerr << "To fill: " << t_f << "\n";
        std::cerr << "Filled: " << e_f << '\n';

        if (t_f != e_f) {
            std::cout << "------------------\n";
            std::cout << " Before recursion: \n";
            disp(zadanie, va_cnt, va_ppp);
            std::cout << "------------------\n";
#if 0
            {
                std::map<int, std::set<int>> candidates;
                for (int i = 0; i < zadanie_size; i++) {
                    if (zadanie[i] == 0) {
                        auto v = get_candidates(i, zadanie, Areas, InverseMap, false);
                        std::set<int> icands{};
                        ed.display_element_address(std::cout, i);
                        std::cout << ": ";
                        for (auto e : v) {
                            icands.insert(e);
                            std::cout << e << ", ";
                        }
                        std::cout << '\n';
                        candidates.insert(std::pair<int, std::set<int>>(i, icands));
                    }
                }
                {
                    for (int i = 0; i < Areas.size(); i++)
                        for (int j = 0; j < Areas.size(); j++)
                            if (i != j) {
                                auto s = get_blocks_intersection(i, j, Areas);
                                std::cout << i << ", " << j << " = " << s.size() << '\n';

                                // exists candidate c in s, which is not in bi - s
                                // eliminate it from bj - s
                                // and vice-versa

                                std::set<int> set_s_u_cands{};
                                for (int e : s)
                                    if (zadanie[e] == 0)
                                        for (auto c : candidates[e])
                                            set_s_u_cands.insert(c);

                                std::set<int> cands_bi_s{};
                                for (int e : Areas[i]) {
                                    if (zadanie[e] == 0 && s.find(e) == s.end()) {
                                        for (int el : candidates[e])
                                            cands_bi_s.insert(el);
                                    }
                                }
                                std::set<int> diff{};
                                std::set_difference(set_s_u_cands.begin(), set_s_u_cands.end(), cands_bi_s.begin(), cands_bi_s.end(), std::inserter(diff, diff.end()));

                                for (int e : Areas[j]) {
                                    if (zadanie[e] == 0 && s.find(e) == s.end()) {
                                        for (int d : diff)
                                            if (candidates[e].find(d) != candidates[e].end()) {
                                                candidates[e].erase(d);
                                                std::cout << "Removed.\n";
                                            }
                                    }
                                }

                                //vice-versa
                                std::set<int> cands_bj_s{};
                                for (int e : Areas[j]) {
                                    if (zadanie[e] == 0 && s.find(e) == s.end()) {
                                        for (int el : candidates[e])
                                            cands_bj_s.insert(el);
                                    }
                                }
                                std::set<int> diffj{};
                                std::set_difference(set_s_u_cands.begin(), set_s_u_cands.end(), cands_bi_s.begin(), cands_bi_s.end(), std::inserter(diffj, diffj.end()));

                                for (int e : Areas[i]) {
                                    if (zadanie[e] == 0 && s.find(e) == s.end()) {
                                        for (int d : diffj)
                                            if (candidates[e].find(d) != candidates[e].end()) {
                                                candidates[e].erase(d);
                                                std::cout << "Removed.\n";
                                            }
                                    }
                                }


                            }

                    for (int i = 0; i < zadanie_size; i++) {
                        if (zadanie[i] == 0) {
                            ed.display_element_address(std::cout, i);
                            std::cout << ": ";

                            for (int e : candidates[i])
                                std::cout << e << ", ";
                            std::cout << '\n';

                        }
                    }

                }

            }
#endif
            SolveSudoku3_with_recursion_ED(t_f - e_f, zadanie_size, zadanie, Areas, InverseMap, ed, 1, disp, va_cnt, va_ppp);

            /*std::cout << "HHHHEEEE\n";*/
        }
        else {
            // print solution
            std::cout << "=================Solution:\n";
            disp(zadanie, va_cnt, va_ppp);
        }

        //disp(zadanie);
        /*for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int idx = 9 * i + j;
                if (zadanie5[idx])
                    std::cout << zadanie5[idx];
                else std::cout << '.';
            }
            std::cout << "\n";
        }*/
    }
    //va_end(args);
}



int main3() {
    
    int zadanie2[]{
        0,0,0, 6,0,7, 0,0,0,
        0,0,3, 0,0,0, 8,0,0,
        0,4,0, 1,0,3, 0,6,0,

        1,0,2, 0,0,0, 3,0,4,
        0,0,0, 0,0,0, 0,0,0,
        5,0,7, 0,0,0, 6,0,8,

        0,6,0, 8,0,2, 0,7,0,
        0,0,9, 0,0,0, 5,0,0,
        0,0,0, 3,0,9, 0,0,0
    };

    int zadanie3[]{
        0,6,8, 0,0,0, 9,1,0,
        2,0,0, 0,0,0, 0,0,3,
        7,0,0, 5,0,6, 0,0,8,

        0,0,3, 0,6,0, 8,0,0,
        0,0,0, 4,0,9, 0,0,0,
        0,0,7, 0,5,0, 6,0,0,

        8,0,0, 6,0,1, 0,0,2,
        5,0,0, 0,0,0, 0,0,1,
        0,2,1, 0,0,0, 4,8,0
    };

    std::vector<std::vector<int>> Area;

    /* Rows */
    for (int i = 0; i < 9; i++)
        RegisterArea(Area, std::vector<int>{ 9*i + 0, 9 * i + 1, 9 * i + 2, 
            9 * i + 3, 9 * i + 4, 9 * i + 5, 
            9 * i + 6, 9 * i + 7, 9 * i + 8});
    /* Columns */
    for (int i = 0; i < 9; i++) {
        RegisterArea(Area, std::vector<int>{ i + 0, i + 9, i + 18,
            i + 27, i + 36, i + 45, i + 54, i + 63, i + 72});
    }
    /* 3x3 Blocks*/
    for (int i =0; i < 3; i++) {
        RegisterArea(Area, std::vector<int>{27 * i + 0, 27 * i + 1, 27 * i + 2, 27 * i + 9,  27 * i + 10, 27 * i + 11, 27 * i + 18, 27 * i + 19, 27 * i + 20});
        RegisterArea(Area, std::vector<int>{27 * i + 3, 27 * i + 4, 27 * i + 5, 27 * i + 12, 27 * i + 13, 27 * i + 14, 27 * i + 21, 27 * i + 22, 27 * i + 23});
        RegisterArea(Area, std::vector<int>{27 * i + 6, 27 * i + 7, 27 * i + 8, 27 * i + 15, 27 * i + 16, 27 * i + 17, 27 * i + 24, 27 * i + 25, 27 * i + 26});
    }

    /* Diagonals */
    RegisterArea(Area, std::vector<int>{0, 10, 20, 30, 40, 50, 60, 70, 80});
    RegisterArea(Area, std::vector<int>{8, 16, 24, 32, 40, 48, 56, 64, 72});

    std::map<int, std::vector<int>> InverseMap;
    BuildMap(InverseMap, Area);

#if 0
    int t_f = count_filled(81, zadanie2);

    int e_f = SolveSudoku(81, zadanie2, Area, InverseMap);

    //int e_f = 0;
    //bool filled = true;
    //int j = 0;
    //while (filled) {
    //    filled = false;
    //    for (int i = 0; i < 81; i++) {
    //        if (zadanie2[i] == 0) {
    //            auto cands = get_candidates(i, zadanie2, Area, InverseMap);
    //            if (cands.size() == 1) {
    //                zadanie2[i] = cands[0];
    //                //no_filled--;
    //                e_f++;
    //                //std::cout << "Filling (" << j + 1 << ") elem " << i << " with " << cands[0] << '\n';
    //                filled = true;
    //            }
    //        }
    //    }

    //    for (int ii = 0; ii < Area.size(); ii++) {
    //        auto res = can_be_uniquely_filled_in_area(ii, zadanie2, Area, InverseMap);
    //        for (auto e : res) {
    //            //std::cout << e.first << " -> " << e.second << '\n';
    //            zadanie2[e.first] = e.second;
    //            //no_filled--;
    //            e_f++;
    //            filled = true;
    //        }
    //    }
    //    j++;
    //}
    std::cout << "To fill: " << t_f  << "\n";
    std::cout << "Filled: " << e_f << '\n';
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int idx = 9 * i + j;
            if (zadanie2[idx])
                std::cout << zadanie2[idx];
            else std::cout << '.';
        }
        std::cout << "\n";
    }

    t_f = count_filled(81, zadanie3);
    e_f = SolveSudoku(81, zadanie3, Area, InverseMap);
    std::cout << "To fill: " << t_f << "\n";
    std::cout << "Filled: " << e_f << '\n';
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int idx = 9 * i + j;
            if (zadanie3[idx])
                std::cout << zadanie3[idx];
            else std::cout << '.';
        }
        std::cout << "\n";
    }
    std::cout << "--------------------------\n";
    int zadanie4[] = {
        6,4,0, 9,7,0, 0,0,5,
        0,0,0, 6,1,0, 0,0,0,
        1,3,0, 0,8,0, 0,0,0,
        
        0,0,4, 0,5,0, 0,0,1,
        0,0,1, 0,9,0, 0,0,0,
        0,0,6, 0,3,1, 7,0,0,

        0,6,3, 1,2,0, 4,9,8,
        0,1,0, 0,4,9, 0,3,0,
        4,0,0, 3,6,8, 0,0,2
    };
   
    /*t_f = count_filled(81, zadanie4);
    e_f = SolveSudoku2(81, zadanie4, Area, InverseMap);
    std::cout << "To fill: " << t_f << "\n";
    std::cout << "Filled: " << e_f << '\n';
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int idx = 9 * i + j;
            if (zadanie4[idx])
                std::cout << zadanie4[idx];
            else std::cout << '.';
        }
        std::cout << "\n";
    }*/
#endif
    int zadanie5[] = {
            0,0,0, 1,0,8, 0,0,3,
            1,0,2, 5,0,0, 8,6,7,
            0,0,0, 0,0,7, 0,0,0,

            3,1,4, 0,0,0, 7,9,6,
            2,5,6, 9,7,1, 3,8,4,
            0,0,0, 4,0,0, 1,2,5,

            0,0,1, 3,0,0, 0,7,0,
            7,9,0, 0,0,0, 4,0,0,
            0,0,0, 7,0,4, 0,0,0
    };
    std::cout << "--------555------------------\n";
#if 0
    int t_f = count_filled(81, zadanie5);
    std::vector<int> filled_elements;
    int e_f = SolveSudoku2(81, zadanie5, Area, InverseMap, filled_elements);
    if (e_f != -1) {
        std::cout << "To fill: " << t_f << "\n";
        std::cout << "Filled: " << e_f << '\n';
        if (t_f != e_f) {
            SolveSudoku3_with_recursion(t_f - e_f, 81, zadanie5, Area, InverseMap);
            /*std::cout << "HHHHEEEE\n";*/
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int idx = 9 * i + j;
                if (zadanie5[idx])
                    std::cout << zadanie5[idx];
                else std::cout << '.';
            }
            std::cout << "\n";
        }
    }
#endif

    Solve(81, zadanie5, Area, InverseMap, disp_3x3);
    return 0;
}



int main4() {
    std::vector<std::vector<int>> Areas3x3;
    init_3x3_areas(Areas3x3);

    //for (auto v: Areas3x3) {
    //    for (auto e : v)
    //        std::cout << e << ", ";
    //    std::cout << '\n';
    //}

    //std::cout << Areas3x3.size() << '\n';

    std::map<int, std::vector<int>> InverseMap3x3;
    BuildMap(InverseMap3x3, Areas3x3);
#if 0    
    int zadanie4[] = {
        0,0,0, 3,2,9, 0,0,0,
        0,0,8, 0,0,0, 7,0,0,
        0,9,5, 0,0,0, 1,2,0,

        7,0,0, 2,0,1, 0,0,8,
        5,0,0, 0,0,0, 0,0,3,
        9,0,0, 6,0,7, 0,0,2,

        0,3,4, 0,0,0, 8,6,0,
        0,0,7, 0,0,0, 2,0,0,
        0,0,0, 1,8,6, 0,0,0
    };

    int t_f = count_filled(81, zadanie4);
    int e_f = SolveSudoku(81, zadanie4, Areas3x3, InverseMap3x3);
    std::cout << "To fill: " << t_f << "\n";
    std::cout << "Filled: " << e_f << '\n';



    

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int idx = 9 * i + j;
            if (zadanie4[idx])
                std::cout << zadanie4[idx];
            else std::cout << '.';
        }
        std::cout << "\n";
    }
 

    int zadanie7[] = {
            5,9,8, 7,1,2, 3,4,6,
            4,6,1, 0,8,0, 7,5,2,
            3,7,2, 6,5,4, 1,9,8,

            1,0,9, 0,0,0, 8,0,3,
            8,0,0, 1,0,0, 4,0,9,
            7,0,0, 0,0,0, 5,0,1,

            2,3,4, 5,9,1, 6,8,7,
            6,1,5, 0,0,0, 9,3,4,
            9,8,7, 4,3,6, 2,1,5
    };
    t_f = count_filled(81, zadanie7);
    std::vector<int> filled_elements;
    e_f = SolveSudoku2(81, zadanie7, Areas3x3, InverseMap3x3, filled_elements);
    std::cout << "To fill: " << t_f << "\n";
    std::cout << "Filled: " << e_f << '\n';

    for (int i = 0; i < 81; i++) {
        if (zadanie7[i] == 0) {
            auto cands = get_candidates(i, zadanie7, Areas3x3, InverseMap3x3);
            std::cout << i << ": ";
            disp_vec(cands);

        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int idx = 9 * i + j;
            if (zadanie7[idx])
                std::cout << zadanie7[idx];
            else std::cout << '.';
        }
        std::cout << "\n";
    }

    std::cout << "=====================\n";
#endif
    // Arto Inkala 2012
    int zadanie6[] = {
        8,0,0, 0,0,0, 0,0,0,
        0,0,3, 6,0,0, 0,0,0,
        0,7,0, 0,9,0, 2,0,0,

        0,5,0, 0,0,7, 0,0,0,
        0,0,0, 0,4,5, 7,0,0,
        0,0,0, 1,0,0, 0,3,0,

        0,0,1, 0,0,0, 0,6,8,
        0,0,8, 5,0,0, 0,1,0,
        0,9,0, 0,0,0, 4,0,0
    };

    Solve(81, zadanie6, Areas3x3, InverseMap3x3, disp_3x3);
    std::cout << "===================\n";
    return 0;
}

int main2() {
    std::vector<std::vector<int>> Area;

    /*  Rows */
    RegisterArea(Area, std::vector<int>{ 0,  1,  2,  3,  4,  5,  6,  7,  8});
    RegisterArea(Area, std::vector<int>{ 9, 10, 11, 12, 13, 14, 15, 16, 17});
    RegisterArea(Area, std::vector<int>{18, 19, 20, 21, 22, 23, 24, 25, 26});
    
    RegisterArea(Area, std::vector<int>{27, 28, 29, 30, 31, 32, 33, 34, 35});
    RegisterArea(Area, std::vector<int>{36, 37, 38, 39, 40, 41, 42, 43, 44});
    RegisterArea(Area, std::vector<int>{45, 46, 47, 48, 49, 50, 51, 52, 53});
    
    RegisterArea(Area, std::vector<int>{54, 55, 56, 57, 58, 59, 60, 61, 62});
    RegisterArea(Area, std::vector<int>{60, 61, 62, 63, 64, 65, 66, 67, 68});
    RegisterArea(Area, std::vector<int>{66, 67, 68, 69, 70, 71, 72, 73, 74});

    RegisterArea(Area, std::vector<int>{75, 76, 77, 78, 79, 80, 81, 82, 83});
    RegisterArea(Area, std::vector<int>{81, 82, 83, 84, 85, 86, 87, 88, 89});
    RegisterArea(Area, std::vector<int>{87, 88, 89, 90, 91, 92, 93, 94, 95});

    RegisterArea(Area, std::vector<int>{ 96,  97,  98,  99, 100, 101, 102, 103, 104});
    RegisterArea(Area, std::vector<int>{102, 103, 104, 105, 106, 107, 108, 109, 110});
    RegisterArea(Area, std::vector<int>{108, 109, 110, 111, 112, 113, 114, 115, 116});

    RegisterArea(Area, std::vector<int>{117, 118, 119, 120, 121, 122, 123, 124, 125});
    RegisterArea(Area, std::vector<int>{126, 127, 128, 129, 130, 131, 132, 133, 134});

    RegisterArea(Area, std::vector<int>{135, 136, 137, 138, 139, 140, 141, 142, 143});
    RegisterArea(Area, std::vector<int>{144, 145, 146, 147, 148, 149, 150, 151, 152});

    RegisterArea(Area, std::vector<int>{153, 154, 155, 156, 157, 158, 159, 160, 161});
    RegisterArea(Area, std::vector<int>{162, 163, 164, 165, 166, 167, 168, 169, 170});


    RegisterArea(Area, std::vector<int>{171, 172, 173, 174, 175, 176, 177, 178, 179});
    RegisterArea(Area, std::vector<int>{177, 178, 179, 180, 181, 182, 183, 184, 185});
    RegisterArea(Area, std::vector<int>{183, 184, 185, 186, 187, 188, 189, 190, 191});

    RegisterArea(Area, std::vector<int>{192, 193, 194, 195, 196, 197, 198, 199, 200});
    RegisterArea(Area, std::vector<int>{198, 199, 200, 201, 202, 203, 204, 205, 206});
    RegisterArea(Area, std::vector<int>{204, 205, 206, 207, 208, 209, 210, 211, 212});

    RegisterArea(Area, std::vector<int>{213, 214, 215, 216, 217, 218, 219, 220, 221});
    RegisterArea(Area, std::vector<int>{219, 220, 221, 222, 223, 224, 225, 226, 227});
    RegisterArea(Area, std::vector<int>{225, 226, 227, 228, 229, 230, 231, 232, 233});

    RegisterArea(Area, std::vector<int>{234, 235, 236, 237, 238, 239, 240, 241, 242});
    RegisterArea(Area, std::vector<int>{243, 244, 245, 246, 247, 248, 249, 250, 251});
    RegisterArea(Area, std::vector<int>{252, 253, 254, 255, 256, 257, 258, 259, 260});

    RegisterArea(Area, std::vector<int>{261, 262, 263, 264, 265, 266, 267, 268, 269});
    RegisterArea(Area, std::vector<int>{270, 271, 272, 273, 274, 275, 276, 277, 278});
    RegisterArea(Area, std::vector<int>{279, 280, 281, 282, 283, 284, 285, 286, 287});

    /* Columns */
    RegisterArea(Area, std::vector<int>{ 54,  75, 96, 117, 135, 153, 171, 192, 213});
    RegisterArea(Area, std::vector<int>{ 55,  76, 97, 118, 136, 154, 172, 193, 214});
    RegisterArea(Area, std::vector<int>{ 56,  77, 98, 119, 137, 155, 173, 194, 215});
    RegisterArea(Area, std::vector<int>{ 57,  78,  99, 120, 138, 156, 174, 195, 216});
    RegisterArea(Area, std::vector<int>{ 58,  79, 100, 121, 139, 157, 175, 196, 217});
    RegisterArea(Area, std::vector<int>{ 59,  80, 101, 122, 140, 158, 176, 197, 218});
    RegisterArea(Area, std::vector<int>{ 60, 81, 102, 123, 141, 159, 177, 198, 219});
    RegisterArea(Area, std::vector<int>{ 61, 82, 103, 124, 142, 160, 178, 199, 220});
    RegisterArea(Area, std::vector<int>{ 62, 83, 104, 125, 143, 161, 179, 200, 221});

    RegisterArea(Area, std::vector<int>{  0, 9,  18, 27, 36, 45, 60, 81, 102});
    RegisterArea(Area, std::vector<int>{  1, 10, 19, 28, 37, 46, 61, 82, 103});
    RegisterArea(Area, std::vector<int>{  2, 11, 20, 29, 38, 47, 62, 83, 104});
    RegisterArea(Area, std::vector<int>{  3, 12, 21, 30, 39, 48, 63, 84, 105});
    RegisterArea(Area, std::vector<int>{  4, 13, 22, 31, 40, 49, 64, 85, 106});
    RegisterArea(Area, std::vector<int>{  5, 14, 23, 32, 41, 50, 65, 86, 107});
    RegisterArea(Area, std::vector<int>{  6, 15, 24, 33, 42, 51, 66, 87, 108});
    RegisterArea(Area, std::vector<int>{  7, 16, 25, 34, 43, 52, 67, 88, 109});
    RegisterArea(Area, std::vector<int>{  8, 17, 26, 35, 44, 53, 68, 89, 110});

    RegisterArea(Area, std::vector<int>{  66, 87, 108, 126, 144, 162, 183, 204, 225});
    RegisterArea(Area, std::vector<int>{  67, 88, 109, 127, 145, 163, 184, 205, 226});
    RegisterArea(Area, std::vector<int>{  68, 89, 110, 128, 146, 164, 185, 206, 227});
    RegisterArea(Area, std::vector<int>{  69, 90, 111, 129, 147, 165, 186, 207, 228});
    RegisterArea(Area, std::vector<int>{  70, 91, 112, 130, 148, 166, 187, 208, 229});
    RegisterArea(Area, std::vector<int>{  71, 92, 113, 131, 149, 167, 188, 209, 230});
    RegisterArea(Area, std::vector<int>{  72, 93, 114, 132, 150, 168, 189, 210, 231});
    RegisterArea(Area, std::vector<int>{  73, 94, 115, 133, 151, 169, 190, 211, 232});
    RegisterArea(Area, std::vector<int>{  74, 95, 116, 134, 152, 170, 191, 212, 233});

    RegisterArea(Area, std::vector<int>{  177, 198, 219, 234, 243, 252, 261, 270, 279});
    RegisterArea(Area, std::vector<int>{  178, 199, 220, 235, 244, 253, 262, 271, 280});
    RegisterArea(Area, std::vector<int>{  179, 200, 221, 236, 245, 254, 263, 272, 281});
    RegisterArea(Area, std::vector<int>{  180, 201, 222, 237, 246, 255, 264, 273, 282});
    RegisterArea(Area, std::vector<int>{  181, 202, 223, 238, 247, 256, 265, 274, 283});
    RegisterArea(Area, std::vector<int>{  182, 203, 224, 239, 248, 257, 266, 275, 284});
    RegisterArea(Area, std::vector<int>{  183, 204, 225, 240, 249, 258, 267, 276, 285});
    RegisterArea(Area, std::vector<int>{  184, 205, 226, 241, 250, 259, 268, 277, 286});
    RegisterArea(Area, std::vector<int>{  185, 206, 227, 242, 251, 260, 269, 278, 287});

    /* Blocks */
    RegisterArea(Area, std::vector<int>{  0, 1, 2,  9, 10, 11, 18, 19, 20});
    RegisterArea(Area, std::vector<int>{  3, 4, 5, 12, 13, 14, 21, 22, 23});
    RegisterArea(Area, std::vector<int>{  6, 7, 8, 15, 16, 17, 24, 25, 26});
    RegisterArea(Area, std::vector<int>{  27, 28, 29, 36, 37, 38, 45, 46, 47});
    RegisterArea(Area, std::vector<int>{  30, 31, 32, 39, 40, 41, 48, 49, 50});
    RegisterArea(Area, std::vector<int>{  33, 34, 35, 42, 43, 44, 51, 52, 53});
    RegisterArea(Area, std::vector<int>{  60, 61, 62, 81, 82, 83, 102, 103, 104});
    RegisterArea(Area, std::vector<int>{  63, 64, 65, 84, 85, 86, 105, 106, 107});
    RegisterArea(Area, std::vector<int>{  66, 67, 68, 87, 88, 89, 108, 109, 110});

    RegisterArea(Area, std::vector<int>{  54, 55, 56, 75, 76, 77, 96, 97, 98});
    RegisterArea(Area, std::vector<int>{  57, 58, 59, 78, 79, 80, 99, 100, 101});
    RegisterArea(Area, std::vector<int>{  117, 118, 119, 135, 136, 137, 153, 154, 155});
    RegisterArea(Area, std::vector<int>{  120, 121, 122, 138, 139, 140, 156, 157, 158});
    RegisterArea(Area, std::vector<int>{  123, 124, 125, 141, 142, 143, 159, 160, 161});
    RegisterArea(Area, std::vector<int>{  171, 172, 173, 192, 193, 194, 213, 214, 215});
    RegisterArea(Area, std::vector<int>{  174, 175, 176, 195, 196, 197, 216, 217, 218});
    RegisterArea(Area, std::vector<int>{  177, 178, 179, 198, 199, 200, 219, 220, 221});


    /*RegisterArea(Area, std::vector<int>{  66, 67, 68, 87, 88, 89, 108, 109, 110});*/
    RegisterArea(Area, std::vector<int>{  69, 70, 71, 90, 91, 92, 111, 112, 113});
    RegisterArea(Area, std::vector<int>{  72, 73, 74, 93, 94, 95, 114, 115, 116});
    RegisterArea(Area, std::vector<int>{  126, 127, 128, 144, 145, 146, 162, 163, 164});
    RegisterArea(Area, std::vector<int>{  129, 130, 131, 147, 148, 149, 165, 166, 167});
    RegisterArea(Area, std::vector<int>{  132, 133, 134, 150, 151, 152, 168, 169, 170});
    RegisterArea(Area, std::vector<int>{  183, 184, 185, 204, 205, 206, 225, 226, 227});
    RegisterArea(Area, std::vector<int>{  186, 187, 188, 207, 208, 209, 228, 229, 230});
    RegisterArea(Area, std::vector<int>{  189, 190, 191, 210, 211, 212, 231, 232, 233});
    
    RegisterArea(Area, std::vector<int>{  180, 181, 182, 201, 202, 203, 222, 223, 224});
    RegisterArea(Area, std::vector<int>{  234, 235, 236, 243, 244, 245, 252, 253, 254});
    RegisterArea(Area, std::vector<int>{  237, 238, 239, 246, 247, 248, 255, 256, 257});
    RegisterArea(Area, std::vector<int>{  240, 241, 242, 249, 250, 251, 258, 259, 260});
    RegisterArea(Area, std::vector<int>{  261, 262, 263, 270, 271, 272, 279, 280, 281});
    RegisterArea(Area, std::vector<int>{  264, 265, 266, 273, 274, 275, 282, 283, 284});
    RegisterArea(Area, std::vector<int>{  267, 268, 269, 276, 277, 278, 285, 286, 287});
    
    /* TODO: */

    std::map<int, std::vector<int>> InverseMap;
    BuildMap(InverseMap, Area);

    /*disp_vec(Area[0]);
    disp_vec(Area[45]);
    disp_vec(Area[72]);*/

    /*for (auto i : InverseMap) {
        for (auto e: i.second)
            std::cout << e << ", ";
        std::cout << '\n';
    }*/
    
    disp_zadanie(zadanie);
    int no_filled = count_filled(288, zadanie);


    int e_f = 0;
    bool filled = true;
    int j = 0;
    while (filled) {
        filled = false;
        for (int i = 0; i < 288; i++) {
            if (zadanie[i] == 0) {
                auto cands = get_candidates(i, zadanie, Area, InverseMap);
                if (cands.size() == 1) {
                    zadanie[i] = cands[0];
                    //no_filled--;
                    e_f++;
                    //std::cout << "Filling (" << j + 1 << ") elem " << i << " with " << cands[0] << '\n';
                    filled = true;
                }
            }
        }

        for (int ii = 0; ii < Area.size(); ii++) {
            auto res = can_be_uniquely_filled_in_area(ii, zadanie, Area, InverseMap);
            for (auto &e : res) {
                //std::cout << e.first << " -> " << e.second << '\n';
                zadanie[e.first] = e.second;
                //no_filled--;
                e_f++;
                filled = true;
            }
        }
        j++;
    }

    

    if (no_filled == e_f) {
        std::cout << "Solution: \n";

    }
    else {
        std::cout << "Problem!\n";
        std::cout << "Elements to fill: " << no_filled << "\n";
        std::cout << "Filed elements: " << e_f << "\n";

    }
    disp_zadanie(zadanie);
    return 0;
    std::cout << Area.size() << '\n';
    
    disp_vec(Area[99]);

    for (auto idx : Area[99]) {
        if (zadanie[idx] == 0) {
            std::cout << idx << ": ";
        
            disp_vec(get_candidates(idx, zadanie, Area, InverseMap));
        }
    }

    for (int i = 0; i < Area.size(); i++) {
        std::cout << "Res " << i << ": ";
        auto res = can_be_uniquely_filled_in_area(i, zadanie, Area, InverseMap);
        for (auto &e : res) {
            std::cout << e.first << "-> " << e.second << '\n';
        }
        std::cout << '\n';
    }
    
    return 0;
}

void disp_RegT8(int* zadanie, ...) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            disp_elem(zadanie[8 * i + j]);
        std::cout << '\n';
    }
}

int main7() {
    int zadanie[] = {
        0,0,5,0, 0,0,0,8,
        0,4,0,3, 0,0,5,0,
        
        0,0, 0,0,0,0, 0,2,
        0,0, 0,0,1,0, 3,0,
        0,2, 0,0,0,5, 0,0,
        6,0, 0,0,8,0, 0,0,

        0,0,2,0, 0,7,0,6,
        5,0,0,0, 0,0,0,0
    };

    int zadanie2[]{
        0,8,7,0, 0,2,0,0,
        3,0,0,0, 5,0,0,0,
        0,7, 1,0,0,0, 2,3,
        5,0, 0,0,0,0, 0,4,
        0,0, 0,3,0,6, 0,7,
        0,0, 4,0,0,0, 0,0,
        2,6,0,0, 0,0,0,0,
        0,0,0,0, 0,0,8,0
    };

    std::vector<std::vector<int>> RegT8_areas;
    init_RegT8_areas(RegT8_areas);
    //for (auto a : RegT8_areas) {
    //    std::cout << "AREA: ";
    //    for (auto e : a)
    //        std::cout << e << ", ";
    //    std::cout << '\n';
    //}
    std::map<int, std::vector<int>> InverseMap_RegT8;
    BuildMap(InverseMap_RegT8, RegT8_areas);
    //disp_RegT8(zadanie);
    Solve(64, zadanie2, RegT8_areas, InverseMap_RegT8, disp_RegT8);
    return 0;
}

int main5() {
    int zadanie[] = {
        0,0,0, 5,2,0, 0,0,0,
        0,0,9, 6,0,0, 3,0,8,
        0,8,0, 0,0,0, 0,0,5,
        0,0,0, 0,4,0, 0,9,0,
        0,0,0, 0,0,0, 0,0,0,
        0,3,0, 0,1,0, 0,0,0,
        4,0,0, 0,0,0, 0,5,0,
        7,0,6, 0,0,9, 1,0,0,
        0,0,0, 0,8,4, 0,0,0
    };

    int zadanie2[] = {
     0,0,6, 9,0,0, 0,7,0,
     0,0,0, 0,0,0, 5,0,0,
     7,5,0, 0,3,0, 0,0,1,
     0,6,1, 0,0,8, 7,3,4,
     9,4,0, 0,0,0, 0,2,6,
     4,7,3, 8,0,0, 2,1,0,
     1,0,0, 0,5,0, 0,9,2,
     0,0,5, 0,0,0, 0,0,0,
     0,3,0, 0,0,4, 9,0,0
    };

    int zadanie3[] = {
         0,0,4, 0,7,0, 0,6,0,
         9,0,0, 0,5,0, 8,1,0,
         0,0,0, 0,4,0, 0,0,0,
         3,1,0, 0,0,9, 0,4,8,
         0,0,0, 0,0,0, 0,0,0,
         2,9,0, 4,0,0, 0,3,6,
         0,0,0, 0,9,0, 0,0,0,
         0,3,2, 0,6,0, 0,0,9,
         0,5,0, 0,1,0, 6,0,0
    };
    int zadanie4[] = {
         0,0,5, 0,9,0, 1,0,0,
         0,0,0, 6,1,2, 0,5,8,
         0,5,0, 2,0,0, 0,0,0,
         0,0,0, 0,0,0, 0,7,1,
         0,0,0, 0,0,0, 0,0,0,
         6,3,0, 0,0,0, 0,0,0,
         0,0,0, 0,0,7, 0,9,0,
         1,4,0, 7,2,9, 0,0,0,
         0,0,3, 0,5,0, 7,0,0
    };
    std::vector<std::vector<int>> Areas_T9_1;
    init_RegT9_1_areas(Areas_T9_1);

    std::map<int, std::vector<int>> InverseMap_RegT9_1;
    BuildMap(InverseMap_RegT9_1, Areas_T9_1);

    //Solve(81, zadanie, Areas_T9_1, InverseMap_RegT9_1, disp_3x3);
    Solve(81, zadanie4, Areas_T9_1, InverseMap_RegT9_1, disp_3x3);

    //int t_f = count_filled(81, zadanie);
    //int e_f = SolveSudoku(81, zadanie, Areas_T9_1, InverseMap_RegT9_1);
    //std::cout << "To fill: " << t_f << "\n";
    //std::cout << "Filled: " << e_f << '\n';
    //for (int i = 0; i < 9; i++) {
    //    for (int j = 0; j < 9; j++) {
    //        int idx = 9 * i + j;
    //        if (zadanie[idx])
    //            std::cout << zadanie[idx];
    //        else std::cout << '.';
    //    }
    //    std::cout << "\n";
    //}
    return 0;
}

int main6() {
    /* samuraj sudoku */

    int zadanie[] = {
        4,0,5, 0,0,6, 0,0,0,        0,0,0, 0,0,7, 0,0,3,
        0,0,0, 8,9,0, 6,0,5,        0,7,0, 0,8,0, 0,0,0,
        0,0,0, 0,4,2, 0,3,0,        0,0,5, 3,6,0, 0,0,9,

        6,0,0, 2,0,9, 0,8,0,        0,0,0, 6,0,2, 0,9,0,
        0,8,2, 0,6,0, 0,0,0,        0,0,0, 0,1,0, 3,8,0,
        0,0,9, 4,0,0, 0,0,6,        9,0,1, 0,0,5, 6,0,2,

        0,0,7, 0,0,4, 0,0,8, 7,1,0, 3,0,0, 0,0,0, 0,7,0,
        0,9,0, 0,0,0, 0,6,0, 0,0,0, 0,5,0, 0,0,6, 9,0,0,
        0,0,0, 0,0,5, 3,0,2, 0,0,4, 1,0,8, 7,0,0, 0,2,0,

                      0,0,9, 0,0,0, 0,0,3,
                      8,0,0, 0,0,0, 0,0,9,
                      7,0,0, 0,0,0, 5,0,0,

        0,5,0, 0,0,6, 2,0,4, 5,0,0, 6,0,7, 3,0,0, 0,0,0,
        0,0,2, 9,0,0, 0,1,0, 0,0,0, 0,3,0, 0,0,0, 0,2,0,
        0,6,0, 0,0,0, 0,0,7, 0,3,6, 2,0,0, 7,0,0, 3,0,0,

        1,0,5, 6,0,0, 8,0,3,        7,0,0, 0,0,5, 2,0,0,
        0,3,8, 0,9,0, 0,0,0,        0,0,0, 0,3,0, 9,6,0,
        0,9,0, 8,0,3, 0,0,0,        0,5,0, 2,0,9, 0,0,4,

        8,0,0, 0,2,1, 4,0,0,        0,7,0, 9,8,0, 0,0,0,
        0,0,0, 0,6,0, 0,7,0,        5,0,3, 0,7,4, 0,0,0,
        2,0,0, 4,0,0, 0,0,0,        0,0,0, 5,0,0, 7,0,1
    };

    std::vector<std::vector<int>> Areas_SAM;
    init_SAM_areas(Areas_SAM);

    std::map<int, std::vector<int>> InverseMap_SAM;
    BuildMap(InverseMap_SAM, Areas_SAM);

    constexpr int Size_SAM = 369;
    /*for (auto v : Areas_Sam)
        disp_vec(v);*/

    disp_SAM(zadanie);
    int t_f = count_filled(Size_SAM, zadanie);
    int e_f = SolveSudoku(Size_SAM, zadanie, Areas_SAM, InverseMap_SAM);
    std::cout << "To fill: " << t_f << "\n";
    std::cout << "Filled: " << e_f << '\n';
    disp_SAM(zadanie);

    int zadanie_from_file[Size_SAM];
    read_SAM_sudokuOLD("08-sam.txt", zadanie_from_file);
    disp_SAM(zadanie_from_file);
    Solve(Size_SAM, zadanie_from_file, Areas_SAM, InverseMap_SAM, disp_SAM);
    
    
    ///*int*/ t_f = count_filled(Size_SAM, zadanie_from_file);
    ///*int*/ e_f = SolveSudoku(Size_SAM, zadanie_from_file, Areas_SAM, InverseMap_SAM);
    //
    //std::cout << "To fill: " << t_f << "\n";
    //std::cout << "Filled: " << e_f << '\n';
    //disp_SAM(zadanie_from_file);

    return 0;
}

int main8() {
    std::string filename = "pokus.txt";

    std::ifstream infile;
    infile.open(filename, std::ifstream::in);
    std::vector<int> exp_sizes = { 9,9,9,9,9,9,9,9,9 };
    int zzadanie[81];
    read_content_sudoku(infile, exp_sizes, content_type::NUMBERS, true, 9, zzadanie);
    disp_3x3(zzadanie);

    std::vector<std::vector<int>> Areas3x3;
    init_3x3_areas(Areas3x3);
    std::map<int, std::vector<int>> InverseMap3x3;
    BuildMap(InverseMap3x3, Areas3x3);
    Solve(81, zzadanie, Areas3x3, InverseMap3x3, disp_3x3);
    infile.close();
    
    return 0;
}

void SAM_displayer::display_element_address(std::ostream& os, int adr)
{
    static const std::vector<std::string> SAM_element_txt_desc{
        "ULt-E(1,1)", "ULt-E(1,2)", "ULt-E(1,3)", "ULt-E(1,4)", "ULt-E(1,5)", "ULt-E(1,6)", "ULt-E(1,7)", "ULt-E(1,8)", "ULt-E(1,9)",
        "URt-E(1,1)", "URt-E(1,2)", "URt-E(1,3)", "URt-E(1,4)", "URt-E(1,5)", "URt-E(1,6)", "URt-E(1,7)", "URt-E(1,8)", "URt-E(1,9)",
        "ULt-E(2,1)", "ULt-E(2,2)", "ULt-E(2,3)", "ULt-E(2,4)", "ULt-E(2,5)", "ULt-E(2,6)", "ULt-E(2,7)", "ULt-E(2,8)", "ULt-E(2,9)",
        "URt-E(2,1)", "URt-E(2,2)", "URt-E(2,3)", "URt-E(2,4)", "URt-E(2,5)", "URt-E(2,6)", "URt-E(2,7)", "URt-E(2,8)", "URt-E(2,9)",
        "ULt-E(3,1)", "ULt-E(3,2)", "ULt-E(3,3)", "ULt-E(3,4)", "ULt-E(3,5)", "ULt-E(3,6)", "ULt-E(3,7)", "ULt-E(3,8)", "ULt-E(3,9)",
        "URt-E(3,1)", "URt-E(3,2)", "URt-E(3,3)", "URt-E(3,4)", "URt-E(3,5)", "URt-E(3,6)", "URt-E(3,7)", "URt-E(3,8)", "URt-E(3,9)",
        "ULt-E(4,1)", "ULt-E(4,2)", "ULt-E(4,3)", "ULt-E(4,4)", "ULt-E(4,5)", "ULt-E(4,6)", "ULt-E(4,7)", "ULt-E(4,8)", "ULt-E(4,9)",
        "URt-E(4,1)", "URt-E(4,2)", "URt-E(4,3)", "URt-E(4,4)", "URt-E(4,5)", "URt-E(4,6)", "URt-E(4,7)", "URt-E(4,8)", "URt-E(4,9)",
        "ULt-E(5,1)", "ULt-E(5,2)", "ULt-E(5,3)", "ULt-E(5,4)", "ULt-E(5,5)", "ULt-E(5,6)", "ULt-E(5,7)", "ULt-E(5,8)", "ULt-E(5,9)",
        "URt-E(5,1)", "URt-E(5,2)", "URt-E(5,3)", "URt-E(5,4)", "URt-E(5,5)", "URt-E(5,6)", "URt-E(5,7)", "URt-E(5,8)", "URt-E(5,9)",
        "ULt-E(6,1)", "ULt-E(6,2)", "ULt-E(6,3)", "ULt-E(6,4)", "ULt-E(6,5)", "ULt-E(6,6)", "ULt-E(6,7)", "ULt-E(6,8)", "ULt-E(6,9)",
        "URt-E(6,1)", "URt-E(6,2)", "URt-E(6,3)", "URt-E(6,4)", "URt-E(6,5)", "URt-E(6,6)", "URt-E(6,7)", "URt-E(6,8)", "URt-E(6,9)",
        "ULt-E(7,1)", "ULt-E(7,2)", "ULt-E(7,3)", "ULt-E(7,4)", "ULt-E(7,5)", "ULt-E(7,6)", 
        "ULt-E(7,7)=Mid-E(1,1)", "ULt-E(7,8)=Mid-E(1,2)", "ULt-E(7,9)=Mid-E(1,3)", "Mid-E(1,4)", "Mid-E(1,5)", "Mid-E(1,6)",
        "Mid-E(1,7)=URt-E(7,1)", "Mid-E(1,8)=URt-E(7,2)", "Mid-E(1,9)=URt-E(7,3)", "URt-E(7,4)", "URt-E(7,5)", "URt-E(7,6)", 
        "URt-E(7,7)", "URt-E(7,8)", "URt-E(7,9)",
        "ULt-E(8,1)", "ULt-E(8,2)", "ULt-E(8,3)", "ULt-E(8,4)", "ULt-E(8,5)", "ULt-E(8,6)",
        "ULt-E(8,7)=Mid-E(2,1)", "ULt-E(8,8)=Mid-E(2,2)", "ULt-E(8,9)=Mid-E(2,3)", "Mid-E(2,4)", "Mid-E(2,5)", "Mid-E(2,6)",
        "Mid-E(2,7)=URt-E(8,1)", "Mid-E(2,8)=URt-E(8,2)", "Mid-E(2,9)=URt-E(8,3)", "URt-E(8,4)", "URt-E(8,5)", "URt-E(8,6)",
        "URt-E(8,7)", "URt-E(8,8)", "URt-E(8,9)",
        "ULt-E(9,1)", "ULt-E(9,2)", "ULt-E(9,3)", "ULt-E(9,4)", "ULt-E(9,5)", "ULt-E(9,6)",
        "ULt-E(9,7)=Mid-E(3,1)", "ULt-E(9,8)=Mid-E(3,2)", "ULt-E(9,9)=Mid-E(3,3)", "Mid-E(3,4)", "Mid-E(3,5)", "Mid-E(3,6)",
        "Mid-E(3,7)=URt-E(9,1)", "Mid-E(3,8)=URt-E(9,2)", "Mid-E(3,9)=URt-E(9,3)", "URt-E(9,4)", "URt-E(9,5)", "URt-E(9,6)",
        "URt-E(9,7)", "URt-E(9,8)", "URt-E(9,9)",
        "Mid-E(4,1)", "Mid-E(4,2)", "Mid-E(4,3)", "Mid-E(4,4)", "Mid-E(4,5)","Mid-E(4,6)","Mid-E(4,7)","Mid-E(4,8)","Mid-E(4,9)",
        "Mid-E(5,1)", "Mid-E(5,2)", "Mid-E(5,3)", "Mid-E(5,4)", "Mid-E(5,5)","Mid-E(5,6)","Mid-E(5,7)","Mid-E(5,8)","Mid-E(5,9)",
        "Mid-E(6,1)", "Mid-E(6,2)", "Mid-E(6,3)", "Mid-E(6,4)", "Mid-E(6,5)","Mid-E(6,6)","Mid-E(6,7)","Mid-E(6,8)","Mid-E(6,9)",
        "LLt-E(1,1)", "LLt-E(1,2)", "LLt-E(1,3)", "LLt-E(1,4)", "LLt-E(1,5)", "LLt-E(1,6)",
        "LLt-E(1,7)=Mid-E(7,1)", "LLt-E(1,8)=Mid(7,2)", "LLt-E(1,9)=Mid-E(7,3)", "Mid-E(7,4)", "Mid-E(7,5)", "Mid-E(7,6)",
        "Mid-E(7,7)=LRt-E(1,1)", "Mid-E(7,8)=LR-E(1,2)", "Mid-E(7,9)=LR-E(1,3)",
        "LRt-E(1,4)", "LRt-E(1,5)", "LRLt-E(1,6)", "LRt-E(1,7)", "LRt-E(1,8)", "LRt-E(1,9)",
        "LLt-E(2,1)", "LLt-E(2,2)", "LLt-E(2,3)", "LLt-E(2,4)", "LLt-E(2,5)", "LLt-E(2,6)",
        "LLt-E(2,7)=Mid-E(8,1)", "LLt-E(2,8)=Mid(8,2)", "LLt-E(2,9)=Mid-E(8,3)", "Mid-E(8,4)", "Mid-E(8,5)", "Mid-E(8,6)",
        "Mid-E(8,7)=LRt-E(2,1)", "Mid-E(8,8)=LR-E(2,2)", "Mid-E(8,9)=LR-E(2,3)",
        "LRt-E(2,4)", "LRt-E(2,5)", "LRLt-E(2,6)", "LRt-E(2,7)", "LRt-E(2,8)", "LRt-E(2,9)",
        "LLt-E(3,1)", "LLt-E(3,2)", "LLt-E(3,3)", "LLt-E(3,4)", "LLt-E(3,5)", "LLt-E(3,6)",
        "LLt-E(3,7)=Mid-E(9,1)", "LLt-E(3,8)=Mid(9,2)", "LLt-E(3,9)=Mid-E(9,3)", "Mid-E(3,4)", "Mid-E(9,5)", "Mid-E(9,6)",
        "Mid-E(9,7)=LRt-E(3,1)", "Mid-E(9,8)=LR-E(3,2)", "Mid-E(9,9)=LR-E(3,3)",
        "LRt-E(3,4)", "LRt-E(3,5)", "LRLt-E(3,6)", "LRt-E(3,7)", "LRt-E(3,8)", "LRt-E(3,9)",
        "LLt-E(4,1)", "LLt-E(4,2)", "LLt-E(4,3)", "LLt-E(4,4)", "LLt-E(4,5)", "LLt-E(4,6)", "LLt-E(4,7)", "LLt-E(4,8)", "LLt-E(4,9)",
        "LRt-E(4,1)", "LRt-E(4,2)", "LRt-E(4,3)", "LRt-E(4,4)", "LRt-E(4,5)", "LRt-E(4,6)", "LRt-E(4,7)", "LRt-E(4,8)", "LRt-E(4,9)",
        "LLt-E(5,1)", "LLt-E(5,2)", "LLt-E(5,3)", "LLt-E(5,4)", "LLt-E(5,5)", "LLt-E(5,6)", "LLt-E(5,7)", "LLt-E(5,8)", "LLt-E(5,9)",
        "LRt-E(5,1)", "LRt-E(5,2)", "LRt-E(5,3)", "LRt-E(5,4)", "LRt-E(5,5)", "LRt-E(5,6)", "LRt-E(5,7)", "LRt-E(5,8)", "LRt-E(5,9)",
        "LLt-E(6,1)", "LLt-E(6,2)", "LLt-E(6,3)", "LLt-E(6,4)", "LLt-E(6,5)", "LLt-E(6,6)", "LLt-E(6,7)", "LLt-E(6,8)", "LLt-E(6,9)",
        "LRt-E(6,1)", "LRt-E(6,2)", "LRt-E(6,3)", "LRt-E(6,4)", "LRt-E(6,5)", "LRt-E(6,6)", "LRt-E(6,7)", "LRt-E(6,8)", "LRt-E(6,9)",
        "LLt-E(7,1)", "LLt-E(7,2)", "LLt-E(7,3)", "LLt-E(7,4)", "LLt-E(7,5)", "LLt-E(7,6)", "LLt-E(7,7)", "LLt-E(7,8)", "LLt-E(7,9)",
        "LRt-E(7,1)", "LRt-E(7,2)", "LRt-E(7,3)", "LRt-E(7,4)", "LRt-E(7,5)", "LRt-E(7,6)", "LRt-E(7,7)", "LRt-E(7,8)", "LRt-E(7,9)",
        "LLt-E(8,1)", "LLt-E(8,2)", "LLt-E(8,3)", "LLt-E(8,4)", "LLt-E(8,5)", "LLt-E(8,6)", "LLt-E(8,7)", "LLt-E(8,8)", "LLt-E(8,9)",
        "LRt-E(8,1)", "LRt-E(8,2)", "LRt-E(8,3)", "LRt-E(8,4)", "LRt-E(8,5)", "LRt-E(8,6)", "LRt-E(8,7)", "LRt-E(8,8)", "LRt-E(8,9)",
        "LLt-E(9,1)", "LLt-E(9,2)", "LLt-E(9,3)", "LLt-E(9,4)", "LLt-E(9,5)", "LLt-E(9,6)", "LLt-E(9,7)", "LLt-E(9,8)", "LLt-E(9,9)",
        "LRt-E(9,1)", "LRt-E(9,2)", "LRt-E(9,3)", "LRt-E(9,4)", "LRt-E(9,5)", "LRt-E(9,6)", "LRt-E(9,7)", "LRt-E(9,8)", "LRt-E(9,9)"
    };

    os << SAM_element_txt_desc[adr];
}

void SAM2_displayer::display_element_address(std::ostream& os, int adr)
{
    static const std::vector<std::string> SAM2_element_txt_desc{
        "UM-E(1,1)", "UM-E(1,2)", "UM-E(1,3)", "UM-E(1,4)", "UM-E(1,5)", "UM-E(1,6)", "UM-E(1,7)", "UM-E(1,8)", "UM-E(1,9)",
        "UM-E(2,1)", "UM-E(2,2)", "UM-E(2,3)", "UM-E(2,4)", "UM-E(2,5)", "UM-E(2,6)", "UM-E(2,7)", "UM-E(2,8)", "UM-E(2,9)",
        "UM-E(3,1)", "UM-E(3,2)", "UM-E(3,3)", "UM-E(3,4)", "UM-E(3,5)", "UM-E(3,6)", "UM-E(3,7)", "UM-E(3,8)", "UM-E(3,9)",
        "UM-E(4,1)", "UM-E(4,2)", "UM-E(4,3)", "UM-E(4,4)", "UM-E(4,5)", "UM-E(4,6)", "UM-E(4,7)", "UM-E(4,8)", "UM-E(4,9)",
        "UM-E(5,1)", "UM-E(5,2)", "UM-E(5,3)", "UM-E(5,4)", "UM-E(5,5)", "UM-E(5,6)", "UM-E(5,7)", "UM-E(5,8)", "UM-E(5,9)",
        "UM-E(6,1)", "UM-E(6,2)", "UM-E(6,3)", "UM-E(6,4)", "UM-E(6,5)", "UM-E(6,6)", "UM-E(6,7)", "UM-E(6,8)", "UM-E(6,9)",
        "Lt-E(1,1)", "Lt-E(1,2)", "Lt-E(1,3)", "Lt-E(1,4)", "Lt-E(1,5)", "Lt-E(1,6)",
        "Lt-E(1,7)=UM-E(7,1)", "Lt-E(1,8)=UM-E(7,2)", "Lt-E(1,9)=UM-E(7,3)", "UM-E(7,4)", "UM-E(7,5)", "UM-E(7,6)",
        "UM-E(7,7)=Rt-E(1,1)", "UM-E(7,8)=Rt-E(1,2)", "UM-E(7,9)=Rt-E(1,3)", "Rt-E(1,4)", "Rt-E(1,5)", "Rt-E(1,6)", 
        "Rt-E(1,7)", "Rt-E(1,8)", "Rt-E(1,9)",
        "Lt-E(2,1)", "Lt-E(2,2)", "Lt-E(2,3)", "Lt-E(2,4)", "Lt-E(2,5)", "Lt-E(2,6)",
        "Lt-E(2,7)=UM-E(8,1)", "Lt-E(2,8)=UM-E(8,2)", "Lt-E(2,9)=UM-E(8,3)", "UM-E(8,4)", "UM-E(8,5)", "UM-E(8,6)",
        "UM-E(8,7)=Rt-E(2,1)", "UM-E(8,8)=Rt-E(2,2)", "UM-E(8,9)=Rt-E(2,3)", "Rt-E(2,4)", "Rt-E(2,5)", "Rt-E(2,6)",
        "Rt-E(2,7)", "Rt-E(2,8)", "Rt-E(2,9)",
        "Lt-E(3,1)", "Lt-E(3,2)", "Lt-E(3,3)", "Lt-E(3,4)", "Lt-E(3,5)", "Lt-E(3,6)",
        "Lt-E(3,7)=UM-E(9,1)", "Lt-E(3,8)=UM-E(9,2)", "Lt-E(3,9)=UM-E(9,3)", "UM-E(9,4)", "UM-E(9,5)", "UM-E(9,6)",
        "UM-E(9,7)=Rt-E(3,1)", "UM-E(9,8)=Rt-E(3,2)", "UM-E(9,9)=Rt-E(3,3)", "Rt-E(3,4)", "Rt-E(3,5)", "Rt-E(3,6)",
        "Rt-E(3,7)", "Rt-E(3,8)", "Rt-E(3,9)",
        "Lt-E(4,1)", "Lt-E(4,2)", "Lt-E(4,3)", "Lt-E(4,4)", "Lt-E(4,5)", "Lt-E(4,6)", "Lt-E(4,7)", "Lt-E(4,8)", "Lt-E(4,9)",
        "Rt-E(4,1)", "Rt-E(4,2)", "Rt-E(4,3)", "Rt-E(4,4)", "Rt-E(4,5)", "Rt-E(4,6)", "Rt-E(4,7)", "Rt-E(4,8)", "Rt-E(4,9)",
        "Lt-E(5,1)", "Lt-E(5,2)", "Lt-E(5,3)", "Lt-E(5,4)", "Lt-E(5,5)", "Lt-E(5,6)", "Lt-E(5,7)", "Lt-E(5,8)", "Lt-E(5,9)",
        "Rt-E(5,1)", "Rt-E(5,2)", "Rt-E(5,3)", "Rt-E(5,4)", "Rt-E(5,5)", "Rt-E(5,6)", "Rt-E(5,7)", "Rt-E(5,8)", "Rt-E(5,9)",
        "Lt-E(6,1)", "Lt-E(6,2)", "Lt-E(6,3)", "Lt-E(6,4)", "Lt-E(6,5)", "Lt-E(6,6)", "Lt-E(6,7)", "Lt-E(6,8)", "Lt-E(6,9)",
        "Rt-E(6,1)", "Rt-E(6,2)", "Rt-E(6,3)", "Rt-E(6,4)", "Rt-E(6,5)", "Rt-E(6,6)", "Rt-E(6,7)", "Rt-E(6,8)", "Rt-E(6,9)",
        "Lt-E(7,1)", "Lt-E(7,2)", "Lt-E(7,3)", "Lt-E(7,4)", "Lt-E(7,5)", "Lt-E(7,6)",
        "Lt-E(7,7)=LM-E(1,1)", "Lt-E(7,8)=LM-E(1,2)", "Lt-E(7,9)=LM-E(1,3)", "LM-E(1,4)", "LM-E(1,5)", "LM-E(1,6)",
        "LM-E(1,7)=Rt-E(7,1)", "LM-E(1,8)=Rt-E(7,2)", "LM-E(1,9)=Rt-E(7,3)", "Rt-E(7,4)", "Rt-E(7,5)", "Rt-E(7,6)",
        "Rt-E(7,7)", "Rt-E(7,8)", "Rt-E(7,9)",
        "Lt-E(8,1)", "Lt-E(8,2)", "Lt-E(8,3)", "Lt-E(8,4)", "Lt-E(8,5)", "Lt-E(8,6)",
        "Lt-E(8,7)=LM-E(2,1)", "Lt-E(8,8)=LM-E(2,2)", "Lt-E(8,9)=LM-E(2,3)", "LM-E(2,4)", "LM-E(2,5)", "LM-E(2,6)",
        "LM-E(2,7)=Rt-E(8,1)", "LM-E(2,8)=Rt-E(8,2)", "LM-E(2,9)=Rt-E(8,3)", "Rt-E(8,4)", "Rt-E(8,5)", "Rt-E(8,6)",
        "Rt-E(8,7)", "Rt-E(8,8)", "Rt-E(8,9)",
        "Lt-E(9,1)", "Lt-E(9,2)", "Lt-E(9,3)", "Lt-E(9,4)", "Lt-E(9,5)", "Lt-E(9,6)",
        "Lt-E(9,7)=LM-E(3,1)", "Lt-E(9,8)=LM-E(3,2)", "Lt-E(9,9)=LM-E(3,3)", "LM-E(3,4)", "LM-E(3,5)", "LM-E(3,6)",
        "LM-E(3,7)=Rt-E(9,1)", "LM-E(3,8)=Rt-E(9,2)", "LM-E(3,9)=Rt-E(9,3)", "Rt-E(9,4)", "Rt-E(9,5)", "Rt-E(9,6)",
        "Rt-E(9,7)", "Rt-E(9,8)", "Rt-E(9,9)",
        "LM-E(4,1)", "LM-E(4,2)", "LM-E(4,3)", "LM-E(4,4)", "LM-E(4,5)", "LM-E(4,6)", "LM-E(4,7)", "LM-E(4,8)", "LM-E(4,9)",
        "LM-E(5,1)", "LM-E(5,2)", "LM-E(5,3)", "LM-E(5,4)", "LM-E(5,5)", "LM-E(5,6)", "LM-E(5,7)", "LM-E(5,8)", "LM-E(5,9)",
        "LM-E(6,1)", "LM-E(6,2)", "LM-E(6,3)", "LM-E(6,4)", "LM-E(6,5)", "LM-E(6,6)", "LM-E(6,7)", "LM-E(6,8)", "LM-E(6,9)",
        "LM-E(7,1)", "LM-E(7,2)", "LM-E(7,3)", "LM-E(7,4)", "LM-E(7,5)", "LM-E(7,6)", "LM-E(7,7)", "LM-E(7,8)", "LM-E(7,9)",
        "LM-E(8,1)", "LM-E(8,2)", "LM-E(8,3)", "LM-E(8,4)", "LM-E(8,5)", "LM-E(8,6)", "LM-E(8,7)", "LM-E(8,8)", "LM-E(8,9)",
        "LM-E(9,1)", "LM-E(9,2)", "LM-E(9,3)", "LM-E(9,4)", "LM-E(9,5)", "LM-E(9,6)", "LM-E(9,7)", "LM-E(9,8)", "LM-E(9,9)"
    };

    os << SAM2_element_txt_desc[adr];
}
