# themis-to-polygon

Tools to convert from Themis contests to Polygon contests.

## Instructions

I will use contest QN5 as example, available here: [contest file](https://drive.google.com/file/d/1GUWiNDQjdCnsOXlCgQYJc_UWFSVM5AhO/view?usp=sharing), [statement file](https://drive.google.com/file/d/1M79b1ipFnkgpBLsXTsa4fSdYeQaNTNNQ/view?usp=sharing).

If you do this for the first time:

1. Download [7-Zip](https://www.7-zip.org/download.html).

2. Add path to `7z.exe` (for example, mine is `"C:\Program Files\7-Zip"`). Here's [how to add path](https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/)

**Step 1: Setup**

1. Create a folder for contest and statement, then download them there.

2. Create a copy of the contest file, and change the extension to `.zip`.

3. Extract the zip file to a folder with the same name; the easiest way is to right-click it and choose `Extract to "[contestName]\"`.

4. Create a folder for each problem, with [Utility.cpp](%5BNO%20TEMPLATE%5D%20Utility.cpp), [Checker.cpp](%5BNO%20TEMPLATE%5D%20Checker.cpp) and [ModelSolution.cpp](%5BNO%20TEMPLATE%5D%20ModelSolution.cpp) inside.

After step 1, the directory should looks as follow:

<details>
  <summary>Directory paths</summary>
  
  ```
  doituyen2020-quangninh05
  ├── QN5.contest
  ├── QN-5.pdf
  ├── QN5.zip
  ├── QN5
  │   ├── Contestants
  |   |   │
  |   |   ...
  │   ├── Tasks
  |   |   ├── MIN
  |   |   |   │
  |   |   |   ...
  |   |   ├── ORIGAMI
  |   |   |   │
  |   |   |   ...
  |   |   └── WORD
  |   |       │
  |   |       ...
  │   ├── Contest.result
  │   ├── ContestantDirectories.txt
  │   ├── TaskDirectories.txt
  │   └── Tasks.config
  ├── doituyen2020-quangninh05-min
  |   ├── Utility.cpp
  |   ├── Checker.cpp
  |   └── ModelSolution.cpp
  ├── doituyen2020-quangninh05-origami
  |   |
  |   ...
  └── doituyen2020-quangninh05-word
      |
      ...
  ```
</details>

**Step 2: Write checker and model solution**.

1. Add sample input/output to test set, which is in `"[contestName]\Tasks\[problemName]"`. Create a folder for each sample, with `"[problemName].inp"/"[problemName].out"` inside.

2. Edit `Utility.cpp` as per the instructions in the comments. After that, compile and run the file.

3. Copy contents from `arrHashValInpOut.txt` to the [designated place](https://github.com/trxbach/themis-to-polygon/blob/main/%5BNO%20TEMPLATE%5D%20Checker.cpp#L84) in `Checker.cpp`.

4. Edit `Checker.cpp` as per the instructions in the comments.

  For more info on how to use testlib.h: [Checkers with testlib.h](https://codeforces.com/blog/entry/18431), [Validators with testlib.h (for functions like readInt() and   readToken()](https://codeforces.com/blog/entry/18426).

  If you want to test it, edit `inf.txt` and `ouf.txt` (created during step 2.2) and compile it. Run `Checker.exe` with command-line `inf.txt ouf.txt ans.txt` (run `Checker.exe inf.txt` in command line, at the same location as the program).

5. Edit `ModelSolution.cpp` as per the instructions in the comments.

After step 2, the directory should looks as follow:

<details>
  <summary>Directory paths</summary>
  
  ```
  doituyen2020-quangninh05
  ├── QN5.contest
  ├── QN-5.pdf
  ├── QN5.zip
  ├── QN5
  │   |
  |   ...
  ├── doituyen2020-quangninh05-min
  |   ├── Utility.cpp
  |   ├── Utility.exe
  |   ├── Checker.cpp
  |   ├── Checker.exe
  |   ├── ModelSolution.cpp
  |   ├── ModelSolution.exe
  |   ├── input
  |   |   |
  |   |   ...
  |   ├── input.zip
  |   ├── arrHashValInpOut.txt
  |   ├── inf.txt
  |   ├── ouf.txt
  |   └── ans.txt
  ├── doituyen2020-quangninh05-origami
  |   |
  |   ...
  └── doituyen2020-quangninh05-word
      |
      ...
  ```
</details>

**Step 3: Add problem to Polygon**

1. Create new problems at `New Problem` button.

2. Set time limit, memory limit (1024 MB) and check `Are test points enabled?` box in `General info` tab.

3. Write statements in `Statement` tab. Remember to write limits in `Scoring` section (check `Show section Scoring` box).

  For more info on how to use (simple) LaTeX: [Overleaf](https://www.overleaf.com/learn), [Kapeli cheat sheet](https://kapeli.com/cheat_sheets/LaTeX_Math_Symbols.docset/Contents/Resources/Documents/index), [Oeis cheat sheet](https://oeis.org/wiki/List_of_LaTeX_mathematical_symbols).

4. Upload `Checker.cpp` in `Checker` tab.

5. Uplaod tests in 
