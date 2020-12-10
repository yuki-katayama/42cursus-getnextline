# 42cursus-getnextline
## 日本語
### 概要
*  メモリーリーク厳禁!!
* ファイルを一行ずつ読み込む
*  読み込み可能なバッファーサイズを可変長で可能である。
* 読み込み時にエラーが何かしらのエラーが出た場合、返り値=-1
* 読み込み行に改行がある(最後の行ではない)場合、返り値=1
* 読み込み行にナル文字(最後の行である)場合、もしくは読み込むものがない場合(EOF)だった場合、返り値=0
* *bonus.c / *bonus.hは、いくつものファイル読み込み(ファイルディスクリプタの考慮)に対応している。

※ todolits.txtに*bonus.cで私が考慮している箇所を記述している。

### コンパイル方法
gcc -Wall -Wextra -Werror main_bonus.c get_next_line_bonus.c  get_ext_line_utils_bonus.c -D BUFFER_SIZE=xx

また、main_bonus.c get_next_line.c get_next_line_utils.c　ファイルでコンパイルすると、ファイルディスクリプタが考慮できていないことが確認できる。

## English
### Summary
* Strictly no memory leaks!
* Reads files line by line.
* Variable length buffer size is possible for reading.
* If there is some kind of error when reading, return value = -1.
* If there is a newline in the read line (not the last line), return value = 1
* If there is a null character in the line to be read (it is the last line), or if there is nothing to read (EOF), return value = 0
* *bonus.c / *bonus.h supports a number of file reads (considering file descriptors).

※ todolits.txt describes the parts of *bonus.c that I take into account.

### How to compile
gcc -Wall -Wextra -Werror main_bonus.c get_next_line_bonus.c get_ext_line_utils_bonus.c -D BUFFER_SIZE=xx

Also, if you compile with the main_bonus.c get_next_line.c get_next_line_utils.c file, you can see that the file descriptors are not taken into account.

![pic-1](https://i.gyazo.com/b13c8f5260b92ccfc6867a4ce282cc38.png)
