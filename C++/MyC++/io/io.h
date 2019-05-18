#ifndef IO_H_
#define IO_H_



class Io
{
	public:
		using iostate = unsigned char;
	private:
		//8位位图
		//0 0 0 0 0  0       0        0 
		//           badbit  failbit  eof
		iostate state = static_cast<iostate>(0);//状态位图
	public:
		Io() { }
		bool eof()//查看eof位
		{
			return state & static_cast<iostate>(1);
		}
		bool fail()//查看failbit和badbit位
		{
			return state & static_cast<iostate>(3);
		}
		bool bad()//查看badbit位
		{
			return state & static_cast<iostate>(1 << 2);
		}
		bool good()//有效状态
		{
			return !eof() && !fail();
		}
		void clear()//状态位复位
		{
			state = static_cast<iostate>(0);
		}
		void clear(iostate flags)//根据给定的flags将流中对应条件的状态位复位 flags将需要恢复的位设置为0
		{
			state &= flags;
		}
		void setstate(iostate flags)
		{
			state = flags;
		}
		iostate rdstate()//返回状态位
		{
			return state;
		}
		int getBit(int pos)
		{
			if (pos > static_cast<int>(sizeof(iostate) * 8) || pos == 0)
				return -1;
			else
				return static_cast<int>(((static_cast<iostate>(1) << (pos - 1)) & state) != 0);
		}
		void setBit(int pos)
		{
			if (pos > static_cast<int>(sizeof(iostate) * 8) || pos == 0)
				return;
			else
				state |= (static_cast<iostate>(1) << (pos - 1));
		}
};
#endif //end
