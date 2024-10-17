// sudoku_solvers2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
//#include <vector>
//#include <map>

//#include "sam2sudoku.cpp"
#include "sam2sudoku.h"
#include <cstdarg>

void pokusdisp(int* zadanie, ...);

void pokusdisp(int* zadanie, ...) {
	va_list args;

	va_start(args, zadanie);
	int cnt = va_arg(args, int);

	if (cnt != 0) {
		std_header* head = va_arg(args, std_header*);

		std::cout << head->rc << ":RC\n";
	}

	va_end(args);
}

void new_function(int* zadanie, ...) {
	va_list args;
	va_start(args, zadanie);

	pokusdisp(zadanie, args);
	va_end(args);
}

const std::string sudoku_types_options[] = {
		"STD",
		"STD_3x3",
		"STD_3x3D",
		"STD_A4x3",
		"REG",
		"REG_T8",
		"REG_T9",
		"REG_T9_2015",
		"REG_T9_2017",
		"SAM",
		"SAM2"
};

enum sudoku_types :int
{
	STD = 0,
	STD_3x3,
	STD_3x3D,
	STD_A4x3,
	REG,
	REG_T8,
	REG_T9,
	REG_T9_2015,
	REG_T9_2017,
	SAM,
	SAM2
};

#if 0
void show_help(const sudoku_types type) {
	switch(type) {
		case STD:
			std::cout << "HERE\n";
			break;
		default: 
			std::cout << "Not yet implemented.";
			break;
	};
}
#endif

void list_sudoku_types(void) {
	std::cout << "[ ";
	bool bFirst = true;
	for (auto& str : sudoku_types_options) {
		if (!bFirst)
			std::cout << " | ";
		else
			bFirst = false;
		std::cout << str;
	}
	std::cout << " ].\n";
}

void show_help(int argc, char**argv) {
	if (argc < 1 || !argv)
		std::cout << "Usage: " << "<executable_name>";
	else
		std::cout << "Usage: " << argv[0];

	std::cout << " [options] <type> <filename>" << std::endl;
	std::cout << "\t<type> - ";
	list_sudoku_types();
#if 0
	{
		
		bool bFirst = true;
		for (auto& str : sudoku_types_options) {
			if (!bFirst)
				std::cout << " | ";
			else
				bFirst = false;
			std::cout << str;
		}
		std::cout << " ]";
	}
#endif
	std::cout << ".\n\t<filename> - the file that is being read as input" << std::endl;
	std::cout << "Options: \n" <<
		"\t-h (--help) - Shows help\n" <<
		"\t-G (--no-header) - File contains just content (must be a specific type)\n" <<
		"\t-H (--skip-header) - Skip file header (must be a specific type)" << std::endl;
}

int main(int argc, char** argv)
{
	if (false)
	{


		std::ifstream iinfile;
		iinfile.open("c:\\users\\mhyck\\source\\repos\\sudoku2solver\\nota_bene-2023_08_2.txt", std::ifstream::in);
		if (!iinfile.good()) {
			std::cerr << "Error opening file.\n";
		}
		else {
			const int n = 8;
			std::vector<int> exp_sizes{};
			for (int i = 0; i < n; i++)
				exp_sizes.push_back(n);

			// allocate memory for zadanie
			int sdk_elements = n * n;
			int* zzadanie = nullptr;
			zzadanie = new int[sdk_elements];

			read_content_sudoku(iinfile, exp_sizes, content_type::NUMBERS, true, n, zzadanie);

			disp_STDBareD(zzadanie, n);

			std::vector<std::vector<int>> AreasSTDBareD;
			init_STDBareD_areas(n, AreasSTDBareD);

			std::map<int, std::vector<int>> InverseMapSTDBareD;
			BuildMap(InverseMapSTDBareD, AreasSTDBareD);
			//std::cout << &std_head << ": HHH\n";
			Solve(sdk_elements, zzadanie, AreasSTDBareD, InverseMapSTDBareD, disp_STDBareD, n);

			iinfile.close();

			delete[] zzadanie;
		}
		return 0;
	}

	//std::ifstream iinfile;
	//iinfile.open("c:\\users\\mhyck\\source\\repos\\sudoku2solver\\RegT9_1.dat", std::ifstream::in);
	//if (!iinfile.good()) {
	//	std::cerr << "Error opening file.\n";
	//}
	//else {
	//	std::vector<std::vector<int>> Area;
	//	if (read_region_map(iinfile, Area, 9)) {
	//		std::cout << "Read areas: " << Area.size() << ".\n";
	//		std::cout << "OK\n";
	//	}
	//	else {
	//		std::cout << "Not OK\n";
	//	}
	//}
	//iinfile.close();
	//return 0;

	/*std_header pokus;
	pokus.rc = 10;
	int zadanie[4] = { 1,2,3,4 };
	new_function(zadanie, 1, &pokus);

	return 0;*/

#if 0
	std::vector<std::vector<int>> aa = generate_areas_from_region_template(region_template_T8);
	for (auto& area : aa) {
		for (auto& elem : area)
			std::cout << elem << ", ";
		std::cout << '\n';
	}
	return 0;
#endif

#if 0
	std::ifstream ifs;
	std::string filename = "tmpl_reg_T8.txt";
	ifs.open(filename, std::ifstream::in);

	std::vector<std::vector<int>> tmpl_reg_T8;

	if (read_region_template_from_file(ifs, 8, tmpl_reg_T8)) {

		for (auto& row : tmpl_reg_T8) {
			for (auto& e : row)
				std::cout << e << ", ";
			std::cout << '\n';
		}

		std::vector<std::vector<int>> aa = generate_areas_from_region_template(tmpl_reg_T8);
		for (auto& area : aa) {
			for (auto& elem : area)
				std::cout << elem << ", ";
			std::cout << '\n';
		}
	}

	ifs.close();

	return 0;

#endif

	if (argc < 2 /*|| argc > 3*/) {
		show_help(argc, argv);
//		if (argc < 1 || !argv)
//			std::cout << "Usage: " << "<executable_name>";
//		else
//			std::cout << "Usage: " << argv[0];
//
//		std::cout << " [options] <type> <filename>" << std::endl;
//		std::cout << "\t<type> - ";
//		list_sudoku_types();
//#if 0
//		{
//			bool bFirst = true;
//			for (auto& str : sudoku_types_options) {
//				if (!bFirst)
//					std::cout << " | ";
//				else
//					bFirst = false;
//				std::cout << str;
//			}
//			std::cout << " ].\n";
//		}
//#endif
//		std::cout << ".\n\t<filename> - the file that is being read as input" << std::endl;
//		std::cout << "Options: \n" <<
//			"\t-h (--help) - Shows help\n" << 
//			"\t-G (--no-header) - File contains just content (must be a specific type)\n" <<
//			"\t-H (--skip-header) - Skip file header (must be a specific type)" << std::endl;

#if 0
		if (argc > 3)
		{
			std::cout << "More than two arguments have been provided.\n";
		}
#endif

		return 0;
	}

	/* Read options */
	int cur_idx = 1;
	bool skip_head = false;
	bool no_head = false;
	bool memory_wise = false;
	while (cur_idx < argc && argv[cur_idx][0] == '-') {
		/*
		 * --skip-header, -H
		 * --no-header, -G
		 * --help, -h
		 */

		//std::cout << argv[cur_idx] << "\n";
		if (!strcmp(argv[cur_idx], "--skip-header") || !strcmp(argv[cur_idx], "-H")) {
			if (skip_head)
				std::cout << "[Warning] Skip header option already selected.\n";
			if (no_head) {
				std::cout << "Cannot use both --skip-header (-H) and --no-header (-G) options.\n";
				return -1;
			}
			skip_head = true;
		}
		else if (!strcmp(argv[cur_idx], "--no-header") || !strcmp(argv[cur_idx], "-G")) {
			if (no_head)
				std::cout << "[Warning] Skip header option already selected.\n";
			if (skip_head) {
				std::cout << "Cannot use both --skip-header (-H) and --no-header (-G) options.\n";
				return -1;
			}
			no_head = true;
		}
		else if (!strcmp(argv[cur_idx], "--help") || !strcmp(argv[cur_idx], "-h")) {
			//show_help_general();
			std::cout << "Usage .... TODO\n";
			return 0;
		}
		else if (!strcmp(argv[cur_idx], "--memory-wise") || !strcmp(argv[cur_idx], "-m")) {
			memory_wise = true;
		}
		else {
			std::cout << "Unknown option '" << argv[cur_idx] << "'.\n";
			return -1;
		}

		cur_idx++;
	}

    // Parse SUDOKU type
	const size_t sudoku_types_count = 11;
	int option = -1;
	sudoku_types type;

	if (cur_idx < argc) {
		/*for (int i = 0; i < sudoku_types_count; i++) {*/
		for (auto i = sudoku_types::STD; i <= sudoku_types::SAM2; i = sudoku_types(i + 1)) {
			//if (!strncmp(sudoku_types_options[i].c_str(), argv[1], sudoku_types_options[i].size())) {
			if (!strcmp(sudoku_types_options[i].c_str(), argv[cur_idx])) {
				option = i;
				type = i;
				break;
			}
		}
	}
	else {
		std::cout << "Missing sudoku type.\n";
		return -1;
	}
	cur_idx++;

	std::cout << "option: " << option << "\n";

	if (option == -1) {
		std::cout << "Error: Unknown sudoku type: `" << argv[1] << "'.\n"
			"Please use one of the ";
		list_sudoku_types();
		std::cout << ".\n";
		return 1;
	}


#if 0
	int filename_idx = -1;
	// Parse the rest of command line
	for (int i = 2; i < argc; i++) {
		if (argv[i][0] == '-') {
			// it is an option
			if (!strcmp("-h", argv[i]) ||
				!strcmp("--help", argv[i])
				) {
				/* show help for a specific type
				 * TODO
				 */
				show_help(type);
				return 0;
			}

			std::cerr << "Unknown option: `` " << argv[i] << " \".\n";
			return 4;
			//std::cerr << argv[i] << '\n';

		}
		else {
			if (filename_idx == -1)
				filename_idx = i;
			else {
				std::cerr << "More than one filename detected.\n";
				return 0;
			}

		}
	}

	if (filename_idx == -1) {
		std::cerr << "No input files detected.\n";
		return 0;
	}
#endif

	int filename_idx = -1;
	if (cur_idx < argc)
		filename_idx = cur_idx;
	else {
		std::cerr << "No input files detected.\n";
		return 0;
	}

	std::ifstream infile;
	infile.open(argv[filename_idx], std::ifstream::in);

	if (!infile.good()) {
		std::cerr << "Error opening file \"" << argv[filename_idx] << "\".\n";
		infile.close();
		return 2;
	}



	switch (option) {
	case sudoku_types::STD: /* STD_3x3 */
	case sudoku_types::STD_3x3: /* STD_3x3D */
	case sudoku_types::STD_3x3D: /* STD_3x3D */
	case sudoku_types::STD_A4x3: /* STD_3x3D */
	{
		//std::vector<int> exp_sizes = { 9,9,9,9,9,9,9,9,9 };
		//int zzadanie[81];
		/* TODO: read header line */
		std_header std_head;
		char header[1024];
		if (option == sudoku_types::STD) {
			if (skip_head || no_head)
			{
				std::cout << "Cannot use options --no-header or --skip-header on general STD type.\n";
				infile.close();
				return -1;
			}
			// Read header
			infile.getline(header, 1024);

			if (!parse_std_header(header, std_head)) {

				infile.close();
				return 3;
			}
		}
		else if (option == sudoku_types::STD_3x3) {
			std_head.rc = std_head.cc = 3;
			std_head.rowsize = std_head.colsize = 9;
			std_head.b_single_letter = true;
			std_head.max_width = 1;
			std_head.cnt_type = content_type::NUMBERS;
			std_head.diagonal = false;
		}
		else if (option == sudoku_types::STD_3x3D) {
			std_head.rc = std_head.cc = 3;
			std_head.rowsize = std_head.colsize = 9;
			std_head.b_single_letter = true;
			std_head.max_width = 1;
			std_head.cnt_type = content_type::NUMBERS;
			std_head.diagonal = true;
		}
		else if (option == sudoku_types::STD_A4x3) {
			std_head.rc = 3;
			std_head.cc = 4;
			std_head.rowsize = std_head.colsize = 12;
			std_head.b_single_letter = true;
			std_head.max_width = 1;
			std_head.cnt_type = content_type::LETTERS;
			std_head.diagonal = true;
		}

		if (skip_head) 
			infile.getline(header, 1024);
		
		/* now - just skipping */
#if 0
		int sdk_maxnum = std_head.colsize; // should equal to rowsize
		bool sdk_single = true;
		if (std_head.cnt_type == content_type::NUMBERS && sdk_maxnum > 9) 
			sdk_single = false;
		if (std_head.cnt_type == content_type::LETTERS && sdk_maxnum > 26)
			sdk_single = false;

		std_head.b_single_letter = sdk_single;
		if (!sdk_single)
			std_head.max_width = 2; // TODO: log_26
		else
			std_head.max_width = 1;
#endif

		std::vector<int> exp_sizes{};
		for (int i = 0; i < std_head.rowsize; i++)
			exp_sizes.push_back(std_head.colsize);

		// allocate memory for zadanie
		int sdk_elements = std_head.colsize * std_head.rowsize;
		int* zzadanie = nullptr;
		zzadanie = new int [sdk_elements];

		if (std_head.cnt_type != content_type::MAPPED_LETTERS)
			read_content_sudoku(infile, exp_sizes, std_head.cnt_type, std_head.b_single_letter, std_head.colsize, zzadanie);
		else {
			read_content_sudoku_mapped(infile, exp_sizes, std_head, zzadanie);
		}

		
		disp_3x3(zzadanie, 1, &std_head);
	
		/*for (int i = 0; i < std_head.rowsize; i++) {
			for (int j = 0; j < std_head.colsize; j++)
				std::cout << zzadanie[i * std_head.colsize + j] << " ";
			std::cout << '\n';
		}*/

		std::vector<std::vector<int>> Areas3x3;
		std::vector<std::string> Area_descs3x3;
		if (!std_head.diagonal) {
			init_rc_x_cc_areas(std_head.rc, std_head.cc, Areas3x3);
			init_rc_x_cc_area_descs(std_head.rc, std_head.cc, Area_descs3x3);
		}
		else {
			init_rc_x_cc_areas(std_head.rc, std_head.cc, Areas3x3, true);
			init_rc_x_cc_area_descs(std_head.rc, std_head.cc, Area_descs3x3, true);
		}
		


		std::map<int, std::vector<int>> InverseMap3x3;
		BuildMap(InverseMap3x3, Areas3x3);
#if 0
		// debug show areas
		for (int i = 0; i < Areas3x3.size(); i++) {
			std::cout << "Area idx = " << i << ": \n";
			disp_sudoku_area(std_head, Areas3x3, i);
			std::cout << "---\n";
		}
#endif

		//std::cout << &std_head << ": HHH\n";
		Standard_displayer sd;
		sd.std_head = &std_head;
		if (memory_wise)
			Solve_ED_AD2(sdk_elements, zzadanie, Areas3x3, Area_descs3x3, InverseMap3x3, sd, disp_3x3, 1, &std_head);
		else
			Solve_ED_AD(sdk_elements, zzadanie, Areas3x3, Area_descs3x3, InverseMap3x3, sd, disp_3x3, 1, &std_head);
		infile.close();
		delete[] zzadanie;
	}
		break;
		case sudoku_types::REG:
		case sudoku_types::REG_T8:
		case sudoku_types::REG_T9:
		case sudoku_types::REG_T9_2015:
		case sudoku_types::REG_T9_2017:
	{
		std::cout << "Regional sudoku: ...\n";

		char header[1024];
		if (option == sudoku_types::REG && (skip_head || no_head)) {
			std::cout << "Cannot use options --skip-head (-G) or --no-head (-H) with general REG type.\n";
			return 0;
		}

		reg_header reg_head;

		if (option == sudoku_types::REG) {
			infile.getline(header, 1024);
			if (!parse_reg_header(header, reg_head)) {

				infile.close();
				return 3;
			}
		}
		else if (option == sudoku_types::REG_T8) {
			//reg_head.rc, reag_head.cc
			reg_head.colsize = reg_head.rowsize = 8;
			reg_head.b_single_letter = true;
			reg_head.cnt_type = content_type::NUMBERS;
			reg_head.diagonal = false;
			reg_head.reg_type = t_reg_type::T8;
			reg_head.max_width = 1;
		}
		else if (option == sudoku_types::REG_T9) {
			//reg_head.rc, reag_head.cc
			reg_head.colsize = reg_head.rowsize = 9;
			reg_head.b_single_letter = true;
			reg_head.cnt_type = content_type::NUMBERS;
			reg_head.diagonal = false;
			reg_head.reg_type = t_reg_type::T9;
			reg_head.max_width = 1;
		}
		else if (option == sudoku_types::REG_T9_2015) {
			//reg_head.rc, reag_head.cc
			reg_head.colsize = reg_head.rowsize = 9;
			reg_head.b_single_letter = true;
			reg_head.cnt_type = content_type::NUMBERS;
			reg_head.diagonal = false;
			reg_head.reg_type = t_reg_type::T9_15;
			reg_head.max_width = 1;
		}
		else if (option == sudoku_types::REG_T9_2017) {
			//reg_head.rc, reag_head.cc
			reg_head.colsize = reg_head.rowsize = 9;
			reg_head.b_single_letter = true;
			reg_head.cnt_type = content_type::NUMBERS;
			reg_head.diagonal = false;
			reg_head.reg_type = t_reg_type::T9_17;
			reg_head.max_width = 1;
		}

		if (skip_head)
			infile.getline(header, 1024);
		
		
		// read sudoku content

		// initialize empty vector of size rowsize x colsize
		int reg_elements = reg_head.rowsize * reg_head.colsize;
		int* zzadanie = new int[reg_elements];
#if 0
		std::vector<int> zzadanie;
		for (int r = 0; r < reg_head.rowsize; r++)
			for (int c = 0; c < reg_head.colsize; c++)
				zzadanie.push_back(0);
#endif

		std::vector<int> exp_sizes{};
		for (int i = 0; i < reg_head.rowsize; i++)
			exp_sizes.push_back(reg_head.colsize);

#if 0
		int reg_maxnum = reg_head.colsize; // should equal to rowsize
		bool reg_single = true;
		if (reg_head.cnt_type == content_type::NUMBERS && reg_maxnum > 9)
			reg_single = false;
		if (reg_head.cnt_type == content_type::LETTERS && reg_maxnum > 26)
			reg_single = false;

		reg_head.b_single_letter = reg_single;
		if (!reg_single)
			reg_head.max_width = 2; // TODO: log_26
		else
			reg_head.max_width = 1;
#endif

		if (!read_content_sudoku(infile, exp_sizes, reg_head.cnt_type, reg_head.b_single_letter, reg_head.colsize, zzadanie)) {
			std::cerr << "Problematic content of the input file '" << argv[filename_idx] << "'.\n";
			infile.close();
			delete[] zzadanie;
			return -1;
		}

		// initialize areas
		std::vector<std::vector<int>> AreasReg;
		init_rect_row_areas(reg_head.rowsize, AreasReg); // rowsize==colsize
		init_rect_col_areas(reg_head.rowsize, AreasReg); // rowsize==colsize
		if (reg_head.diagonal)
			init_rect_diag_areas(reg_head.rowsize, AreasReg); // rowsize==colsize
		// initialize area_descs
		std::vector<std::string> area_txt_descs{};
		
		for (int i = 0; i < reg_head.rowsize; i++) {
			area_txt_descs.push_back({ "R" + std::to_string(i + 1) });
		}
		for (int i = 0; i < reg_head.colsize; i++) {
			area_txt_descs.push_back({ "C" + std::to_string(i + 1) });
		}
		if (reg_head.diagonal) {
			area_txt_descs.push_back({ "D1" });
			area_txt_descs.push_back({ "D2" });
		}
		for (int i = 0; i < reg_head.rowsize; i++) {
			area_txt_descs.push_back({ "Reg" + std::to_string(i+1)});
		}

		switch (reg_head.reg_type)
		{
		case t_reg_type::TN:
			break;
		case t_reg_type::T8:
			for (auto& a : generate_areas_from_region_template(region_template_T8))
				AreasReg.push_back(a);
			break;
		case t_reg_type::T9:
			for (auto& a : generate_areas_from_region_template(region_template_T9))
				AreasReg.push_back(a);
			break;
		case t_reg_type::T9_15:
			for (auto& a : generate_areas_from_region_template(region_template_T9_15))
				AreasReg.push_back(a);
			break;
		case t_reg_type::T9_17:
			for (auto& a : generate_areas_from_region_template(region_template_T9_17))
				AreasReg.push_back(a);
			break;
		case t_reg_type::T_IF:
			{
			std::vector<std::vector<int>> region_template;
			if (!read_region_template_from_file(infile, reg_head.rowsize, region_template)) {
				std::cerr << "Error parsing internal regional pattern.\n";
				infile.close();
				delete[] zzadanie;
				return -5;
			}
			else {
				for (auto& a : generate_areas_from_region_template(region_template))
					AreasReg.push_back(a);
			}
		}
			break;
		case t_reg_type::T_EF: {
			std::ifstream region_file;
			region_file.open(reg_head.reg_ext_filename, std::ifstream::in);
			if (!region_file.good()) {
				std::cerr << "Error opening region file '" << reg_head.reg_ext_filename << "'.\n";
				region_file.close();
				infile.close();
				delete[] zzadanie;
				return -5;
			}
			else {
				std::vector<std::vector<int>> region_template;
				if (read_region_template_from_file(region_file, reg_head.rowsize, region_template)) {
					for (auto& a : generate_areas_from_region_template(region_template))
						AreasReg.push_back(a);
					region_file.close();
				}
				else {
					std::cerr << "Error reading template from file.\n";
					region_file.close();
					delete[] zzadanie;
					return -6;
				}
			}
		}
			break;
		default:
			break;
		};

		//std::cout << "HHH\n";
		std::map<int, std::vector<int>> InverseMapReg;
		BuildMap(InverseMapReg, AreasReg);
		//std::cout << &std_head << ": HHH\n";
		Standard_displayer sd;
		sd.std_head = &reg_head;
		//Solve_ED(reg_elements, zzadanie, AreasReg, InverseMapReg, sd, disp_3x3, 1, &reg_head);
		if (memory_wise)
			Solve_ED_AD2(reg_elements, zzadanie, AreasReg, area_txt_descs, InverseMapReg, sd, disp_3x3, 1, &reg_head);
		else
			Solve_ED_AD(reg_elements, zzadanie, AreasReg, area_txt_descs, InverseMapReg, sd, disp_3x3, 1, &reg_head);
		// TODO: Add solving method with vector
		delete[] zzadanie;
	};
		break;
		case sudoku_types::SAM:
		{
			const int total_SAM_size = 369;
			int* zzadanie = new int[total_SAM_size];
			if (read_SAM_sudoku(infile, zzadanie)) {
				// initialize areas
				std::vector<std::vector<int>> AreasSAM;
				init_SAM_areas(AreasSAM);
				std::vector<std::string> Area_txt_descsSAM;
				init_SAM_area_txt_descs(Area_txt_descsSAM);
				std::map<int, std::vector<int>> InverseMapSAM;
				BuildMap(InverseMapSAM, AreasSAM);
				//std::cout << &std_head << ": HHH\n";
				std_header std_head;
				std_head.rowsize = 9;
				std_head.colsize = 9;
				std_head.max_width = 1;
				std_head.b_single_letter = true;
				std_head.cnt_type = content_type::NUMBERS;
				std_head.diagonal = false;
				
				SAM_displayer SAMd;
				SAMd.std_head = &std_head;

				if (memory_wise)
					Solve_ED_AD2(total_SAM_size, zzadanie, AreasSAM, Area_txt_descsSAM, InverseMapSAM, SAMd, disp_SAM);
				else
					Solve_ED_AD(total_SAM_size, zzadanie, AreasSAM, Area_txt_descsSAM, InverseMapSAM, SAMd, disp_SAM);

				//Solve(total_SAM_size, zzadanie, AreasSAM, InverseMapSAM, disp_SAM);
				delete[] zzadanie;
				infile.close();
				return 0;
			}
			else {
				std::cerr << "Error parsing input file.\n";
				delete[] zzadanie;
				infile.close();
				return -1;
			}

		}
		break;
		case sudoku_types::SAM2:
		{
			const int total_SAM2_size = 288;
			int* zzadanie = new int[total_SAM2_size];
			if (read_SAM2_sudoku(infile, zzadanie)) {
				// initialize areas
				std::vector<std::vector<int>> AreasSAM2;
				init_SAM2_areas(AreasSAM2);
				std::vector<std::string> Area_txt_descsSAM2;
				init_SAM2_area_txt_descs(Area_txt_descsSAM2);

				std::map<int, std::vector<int>> InverseMapSAM2;
				BuildMap(InverseMapSAM2, AreasSAM2);
				//std::cout << &std_head << ": HHH\n";
								//std::cout << &std_head << ": HHH\n";
				std_header std_head;
				std_head.rowsize = 9;
				std_head.colsize = 9;
				std_head.max_width = 1;
				std_head.b_single_letter = true;
				std_head.cnt_type = content_type::NUMBERS;
				std_head.diagonal = false;

				SAM2_displayer SAM2d;
				SAM2d.std_head = &std_head;
				if (memory_wise)
					Solve_ED_AD2(total_SAM2_size, zzadanie, AreasSAM2, Area_txt_descsSAM2, InverseMapSAM2, SAM2d, disp_SAM2);
				else
					Solve_ED_AD(total_SAM2_size, zzadanie, AreasSAM2, Area_txt_descsSAM2, InverseMapSAM2, SAM2d, disp_SAM2);

				//Solve(total_SAM2_size, zzadanie, AreasSAM2, InverseMapSAM2, disp_SAM2);
				delete[] zzadanie;
				infile.close();
				return 0;
			}
			else {
				std::cerr << "Error parsing input file.\n";
				delete[] zzadanie;
				infile.close();
				return -1;
			}
		}
		break;

	};

	infile.close();
	return 0;

	//cout << "argv[1] = " << argv[1] << endl;

	//if (!strncmp(argv[1], "REG", 3)) {
	//	regionsudokuboard rsdk;

	//	if (rsdk.read_sudoku(argv[2])) {
	//		rsdk.display_sudoku();
	//		cout << endl;
	//		if (rsdk.has_region)
	//		{
	//			rsdk.print_regionmap();
	//			cout << endl;
	//			rsdk.gen_regions();
	//		}
	//		rsdk.solve_recursive(0);
	//	}

	//	return 0;
	//}


	//if (!strncmp(argv[1], "STD", 3)) {
	//	//	cout << "HERE" << endl;
	//	sudokuboard sdk;

	//	if (sdk.read_sudoku(argv[2])) {
	//		sdk.solve_recursive(0);
	//	}

	//	return 0;
	//}

	//if (!strncmp(argv[1], "SAM", 3)) {
	//	samsudoku sam;

	//	sam.init_field();
	//	sam.read_sudoku(argv[2]);
	//	//sam.display_sudoku();
	//	//cout << endl;
	//	sam.solve_middle_recursive(0);

	//	return 0;
	//}

	
}
