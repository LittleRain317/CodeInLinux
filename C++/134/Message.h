#ifndef __MESSAGE_H_
#define __MESSAGE_H_

#include <string>
#include <vector>
class Folder;
//行为像指针
class Message
{
	friend class Folder;
	private:
		std::string contents; // 实际消息文本
		std::vector<Folder *> folers;	// 包含本message的folder
		// 工具函数
		void add_to_Folders(const Message&);
		void remove_from_Folders();
	public:
		explicit Message(const std::string &str = "") : contents(str) { }
		void save(Folder &);
		void remove(Folder &);
		Message(const Message &);
		~Message();
		Message& operator= (const Message &);

};
#endif
