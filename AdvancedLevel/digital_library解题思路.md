# 解题思路
- 方法
	- 按照title, author, key word, publisher, year等属性建立倒排索引；
	- 具体倒排索引可以用map<string, set<string>> 代替，key就是那5种属性，value是符合该属性下的书的ID的集合；
	- 按照查找的方法，从倒排索引里按照对应的属性输出书的ID；
> **倒排索引**：倒排索引源于实际应用中需要根据属性的值来查找记录。这种索引表中的每一项都包括一个属性值和具有该属性值的各记录的地址。由于不是由记录来确定属性值，而是由属性值来确定记录的位置，因而称为倒排索引(inverted index)。

- 细节实现
	- 从键盘连续输入单词存入变量：
		- cin: 会过滤掉不可见字符(空格 TAB键，回车);
		- istream--->getline
			- cin.getline(char* s, streamsize n): s是指向c-string的指针，n是字符串最大数量，默认换行符为分隔符(字符串终止符)
			- cin.getline(char* s, streamsize n, char delim):delim是显式分隔符
		- string--->getline
			- getline(istream& is, string& str, char delim): is是字符串输入流， str是字符串存储地址，delim是显式分隔符(字符串终止符)；
			- getline(istream& is, string& str):默认换行符为字符串分隔符；
		- istream--->get
			- cin.get()/cin.get(char &c):从输入流中提取一个字符；
			- cin.get(char* s, streamsize n)
			- cin.get(char* s, streamsize n, char delim)
		- cstdio--->gets
			- char* gets(char* str): 从标准输入流中读取字符串并存入c-string中，直到遇到换行符或者文件终止符，str中不会包含换行符，str中会自动附加'\0'；
> **注**：getline会忽略掉输入流中的delim，不影响下一个字符串的输入，但是get不会忽略掉输入流中的delim，会作为下一个待提取的字符，一般情况下，get应该这样使用，cin.get(str, 250).get()。
	- 字符串分词：用stringstream/istringstream实现