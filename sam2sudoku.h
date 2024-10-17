#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <set>

enum class content_type
{
    NUMBERS,
    LETTERS,
    MAPPED_LETTERS
};

const std::string txt_content_type[] =
{
	"N",
	"A",
    "M"
};

struct std_header {
	int rc;
	int cc;
	int rowsize;
	int colsize;
	content_type cnt_type;
	bool diagonal;
    std::map<std::string, int> ascii_to_int_mapping;
    std::map<int, std::string> int_to_ascii_mapping;
    bool b_single_letter;
    int max_width;
};


enum class t_reg_type
{
    TN,
    T8,
    T9,
    T9_15,
    T9_17,
    T_IF,
    T_EF
};

const std::string txt_reg_type[] =
{
    "TN",
    "T8",
    "T9",
    "T9-15",
    "T9-17",
    "T_IF",
    "T_EF"
};


struct reg_header: std_header {
    //int rc;
    //int cc;
    //int rowsize;
    //int colsize;
    //content_type cnt_type;
    //bool diagonal;
    //std::map<std::string, int> ascii_mapping;
    t_reg_type reg_type;
    bool internal;
    std::string reg_ext_filename;
};

struct Element_displayer
{
    virtual void display_element(std::ostream& os, int e) = 0;
    virtual void display_element_address(std::ostream& os, int adr) = 0;
};

struct Standard_displayer : Element_displayer
{
    std_header* std_head;
    virtual void display_element(std::ostream& os, int e);
    virtual void display_element_address(std::ostream& os, int adr);
};

struct SAM_displayer : Standard_displayer
{
    //std_header* std_head;
    virtual void display_element_address(std::ostream& os, int adr);
};

struct SAM2_displayer : Standard_displayer
{
    //std_header* std_head;
    virtual void display_element_address(std::ostream& os, int adr);
};


bool parse_std_header(char *header, std_header &std_head);

void BuildMap(std::map<int, std::vector<int>>& InverseMap, std::vector<std::vector<int>>& Areas);

bool read_content_sudoku(std::ifstream& infile, const std::vector<int>& expected_sizes, content_type sdk_type, bool single_value, int maxvalue, int* zadanie);
bool read_content_sudoku_vec(std::ifstream& infile, const std::vector<int>& expected_sizes, content_type sdk_type, bool single_value, int maxvalue, std::vector<int>& zadanie);

bool read_content_sudoku_mapped(std::ifstream& infile, const std::vector<int>& expected_sizes, const std_header& std_head, int* zadanie);

void Solve(int zadanie_size, int* zadanie, std::vector<std::vector<int>>& Area, std::map<int, std::vector<int>>& InverseMap, void(disp(int*, ...)), ...);
void Solve_ED(int zadanie_size, int* zadanie, std::vector<std::vector<int>>& Area, std::map<int, std::vector<int>>& InverseMap, Element_displayer& ed, void(disp(int*, ...)), ...);
void Solve_ED_AD(int zadanie_size, int* zadanie, const std::vector<std::vector<int>>& Areas, const std::vector<std::string>& Area_descs, const std::map<int, std::vector<int>>& InverseMap, Element_displayer& ed, void(disp(int*, ...)), ...);
void Solve_ED_AD2(int zadanie_size, int* zadanie, const std::vector<std::vector<int>>& Areas, const std::vector<std::string>& Area_descs, const std::map<int, std::vector<int>>& InverseMap, Element_displayer& ed, void(disp(int*, ...)), ...);

void init_STDBareD_areas(int n, std::vector<std::vector<int>>& STDBareD_areas);
void disp_STDBareD(int* zadanie, ...);

void disp_elem3(int e, const std_header *std_head/*, int width*/);
void disp_elem3_os(std::ostream& ofs, int e, const std_header* std_head /*, int width*/);
void disp_3x3(int* zadanie, ...);
void init_3x3_areas(std::vector<std::vector<int>>& Areas_3x3);
void init_3x3D_areas(std::vector<std::vector<int>>& Areas_3x3D);
void init_rc_x_cc_areas(int rc, int cc, std::vector<std::vector<int>>& Areas_rc_x_cc, bool add_diagonals = false);
void init_rc_x_cc_area_descs(int rc, int cc, std::vector<std::string>& Area_descs_rc_x_cc, bool add_diagonals = false);
void init_rect_row_areas(int size, std::vector<std::vector<int>>& Areas_rc_x_cc);
void init_rect_col_areas(int size, std::vector<std::vector<int>>& Areas_rc_x_cc);
void init_rect_diag_areas(int size, std::vector<std::vector<int>>& Areas_rc_x_cc);
void apply_indent(int level);
void disp_vec(const std::vector<int>& vec, std::ostream& os = std::cout);
bool read_region_map(std::ifstream& infile, std::vector<std::vector<int>>& Area, int size);
void skip_ws(char*& pom);
void dump_reg_header(const reg_header& reg_head);
bool parse_reg_header(char* header, reg_header& reg_head);

std::vector<std::vector<int>> generate_areas_from_region_template(std::vector<std::vector<int>>& region_template);
extern std::vector<std::vector<int>> region_template_T8;
extern std::vector<std::vector<int>> region_template_T9;
extern std::vector<std::vector<int>> region_template_T9_15;
extern std::vector<std::vector<int>> region_template_T9_17;
bool read_region_template_from_file(std::ifstream& ifs, int n_dim, std::vector<std::vector<int>>& region_template);
std::set<int> get_blocks_intersection(int blockIdx1, int blockIdx2, const std::vector<std::vector<int>>& Areas);

void disp_sudoku_area(std_header& std_head, const std::vector<std::vector<int>> Areas, int areaIdx);

/* SAM */
bool read_SAM_sudoku(std::ifstream& infile, int* zadanie);
bool read_SAM_sudoku_vec(std::ifstream& infile, std::vector<int>& zadanie);
void init_SAM_areas(std::vector<std::vector<int>>& Areas_SAM);
void disp_SAM(int* zadanie, ...);
void init_SAM_area_txt_descs(std::vector<std::string>& Area_txt_descs_SAM);
/* SAM2 */
bool read_SAM2_sudoku(std::ifstream& infile, int* zadanie);
bool read_SAM2_sudoku_vec(std::ifstream& infile, std::vector<int>& zadanie);
void init_SAM2_areas(std::vector<std::vector<int>>& Areas_SAM2);
void disp_SAM2(int* zadanie, ...);
void init_SAM2_area_txt_descs(std::vector<std::string>& Area_txt_descs_SAM2);


