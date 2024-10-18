# sudoku2solver
Human-like methods for solving sudoku puzzle

It contains memory-less and memory-wise methods. Memory-less method at each step recomputes candidate(s) for a respective field and tries to reason about it. Memory-wise method remembers all candidates for all unfilled elements and combines knowledge to achieve more elimination. Usually, memory-wise method is more successful.

Basic human-like reasoning:

1) SFE(element): Each element belongs to several blocks and if there is a single candidate value that is missing from the union of filled elements, then it is chosen to be filled.
2) SFA(element,block): Computes candidates for elements in a block and if candidates for element contains candidate, which cannot be filled in the remaining elements of the block, then this candidate is chosen to be filled.
3) SFN(element): Variation on SFE, there are several candidates for filling element, it speculatively tries to fill them and if there is direct problem in another block (multiple filled value), the candidate is disregarded and eliminated from the list of candidates. If after eliminating there is a single candidate, it is chosen to be filled.

Memory-wise method works with full list of candidates for each yet unfilled element. Unsuitable candidates from SFN method are remembered and this helps to achieve more fillable elements. Moreover, it also checks intersections of pairs of blocks (b_i, b_j) (usually, row/column and area_block) and if there is a candidate which can be filled only in the intersection s and not in remaining elements of a block b_i (b_i - s), then this candidate can be removed from candidates for all remaining elements of block b_j (b_j - s) and vice-versa.

# Command line description

`sudoku2solver [options] <sudoku-type> <filename>`

## options

`-h` (`--help`) - shows help
`-H`(`--skip-header`) - input file does contain header, but `<sudoku-type>` is fully specified. It skips reading the header.
`-G` (`--no-header`) - input file contains just sudoku data (`<sudoku-type>` must be specific).
`-m` (`--memory-wise`) - use memory-wise method for solving, other-wise memory-less method is used.

## <sudoku-type>

* STD - Standard sudoku - header must be in input file 
* STD_3x3 - Standard 9x9 numeric sudoku with 3x3 area blocks
* STD_3x3D - Diagonal 9x9 numeric sudoku with 3x3 area blocks
* STD_A4x3 - Standard 12x12 letter sudoku (A-L) with 3x4 area blocks
* REG - Regional sudoku - header must be in input file 
* REG_T8 - Specific 8x8 regional sudoku
* REG_T9 - Specific 9x9 regional sudoku
* REG_T9_2015 - Specific 9x9 regional sudoku
* REG_T9_2017 - Specific 9x9 regional sudoku
* SAM - Samurai sudoku (5x 9x9 classical numeric sudoku)
* SAM2 - Samurai2 sudoku (4x 9x9 classical numeric sudoku)

## Input file header

### STD

`rr` `cc` `A|N|M` `S|D` `[<comma separated list_of_mapped_letters>]`

`rr` - area block size rows
`cc` - area block size cols

`A` - letters (A-Z, AA-ZZ, etc.)
`N` - numeric values (0-9,10-99, etc.)
`M` - mapped letters 

`S` - standard
`D` - diagonal

### REG
`rr` `cc` `A|N` `S|D` `<reg-type>`

`rr` `cc` must be chosen such that `rr` x `cc` is equal to sudoku size

Remaining parameters `A`, `N`, `S`, `D` have same meaning as in STD case.

`<reg-type>` - One of the `T8`, `T9`, `T9-15`, `T9-17`, `TN`, `TR`, `TF <filename>`

`TN` - no regional blocks (probably no reasonable solution)

`TR` - reads regional blocks specification from input file. After header and <sudoku data> there is a table in the size of sudoku of comma separated region identifiers (numbered 1-...), which specify to which region block belong elements of sudoku.

`TF <region_blocks_filename>` - reads region blocks specification from `<region_ blocks_filename>`



