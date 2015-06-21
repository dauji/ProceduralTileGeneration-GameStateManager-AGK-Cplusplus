#ifndef _H_AGKDELETE_
#define _H_AGKDELETE_

class AGK_Delete
{
private:
	int ID1_;
	int ID2_;
	int ID3_;
	int ID4_;
	const char * type;
	void AGK_DeleteFunction(int ID1, int ID2, int ID3, int ID4, const char * TYPE);
	void AGK_DeleteFunction(int ID1, int ID2, int ID3, const char * TYPE);
	void AGK_DeleteFunction(int ID1, int ID2, const char * TYPE);
	void AGK_DeleteFunction(int ID1, const char * TYPE);
	enum OBJTYPE { text, button, sprite };
	OBJTYPE TypeConversion(std::string type);
public:
	AGK_Delete(int ID1, int ID2, int ID3, int ID4, const char * TYPE);
	AGK_Delete(int ID1, int ID2, int ID3, const char * type);
	AGK_Delete(int ID1, int ID2, const char * type);
	AGK_Delete(int ID1, const char * type);
	AGK_Delete();
};

#endif