#include <iostream>
#include "AGK_Delete.h"
#include "template.h"

AGK_Delete::AGK_Delete(int ID1, int ID2, int ID3, int ID4, const char * TYPE)
{
	ID1_ = ID1;
	ID2_ = ID2;
	ID3_ = ID3;
	ID4_ = ID4;
	type = TYPE;

	AGK_Delete::AGK_DeleteFunction(ID1_, ID2_, ID3_, ID4_, type);
}

AGK_Delete::AGK_Delete(int ID1, int ID2, int ID3, const char * TYPE)
{
	ID1_ = ID1;
	ID2_ = ID2;
	ID3_ = ID3;
	type = TYPE;

	AGK_Delete::AGK_DeleteFunction(ID1_, ID2_, ID3_, type);
}

AGK_Delete::AGK_Delete(int ID1, int ID2, const char * TYPE)
{
	ID1_ = ID1;
	ID2_ = ID2;
	type = TYPE;

	AGK_Delete::AGK_DeleteFunction(ID1_, ID2_, type);
}

AGK_Delete::AGK_Delete(int ID1, const char * TYPE)
{
	ID1_ = ID1;
	type = TYPE;

	AGK_Delete::AGK_DeleteFunction(ID1_, type);
}

AGK_Delete::OBJTYPE AGK_Delete::TypeConversion(std::string type)
{
	if (type == "TEXT") return text;
	if (type == "BUTTON") return button;
	if (type == "SPRITE") return sprite;
}

void AGK_Delete::AGK_DeleteFunction(int ID1, int ID2, int ID3, int ID4, const char * TYPE)
{
	switch (AGK_Delete::TypeConversion(TYPE))
	{
	case AGK_Delete::OBJTYPE::text: agk::DeleteText(ID1); agk::DeleteText(ID2); agk::DeleteText(ID3); agk::DeleteText(ID4); break;
	case AGK_Delete::OBJTYPE::button: agk::DeleteVirtualButton(ID1); agk::DeleteVirtualButton(ID2); agk::DeleteVirtualButton(ID3); agk::DeleteVirtualButton(ID4); break;
	case AGK_Delete::OBJTYPE::sprite: agk::DeleteSprite(ID1); agk::DeleteSprite(ID2); agk::DeleteSprite(ID3); agk::DeleteSprite(ID4); break;
	}
}

void AGK_Delete::AGK_DeleteFunction(int ID1, int ID2, int ID3, const char * TYPE)
{
	switch (AGK_Delete::TypeConversion(TYPE))
	{
	case AGK_Delete::OBJTYPE::text: agk::DeleteText(ID1); agk::DeleteText(ID2); agk::DeleteText(ID3); break;
	case AGK_Delete::OBJTYPE::button: agk::DeleteVirtualButton(ID1); agk::DeleteVirtualButton(ID2); agk::DeleteVirtualButton(ID3); break;
	case AGK_Delete::OBJTYPE::sprite: agk::DeleteSprite(ID1); agk::DeleteSprite(ID2); agk::DeleteSprite(ID3); break;
	}
}

void AGK_Delete::AGK_DeleteFunction(int ID1, int ID2, const char * TYPE)
{
	switch (AGK_Delete::TypeConversion(TYPE))
	{
	case AGK_Delete::OBJTYPE::text: agk::DeleteText(ID1); agk::DeleteText(ID2); break;
	case AGK_Delete::OBJTYPE::button: agk::DeleteVirtualButton(ID1); agk::DeleteVirtualButton(ID2); break;
	case AGK_Delete::OBJTYPE::sprite: agk::DeleteSprite(ID1); agk::DeleteSprite(ID2); break;
	}
}

void AGK_Delete::AGK_DeleteFunction(int ID1, const char * TYPE)
{
	switch (AGK_Delete::TypeConversion(TYPE))
	{
	case AGK_Delete::OBJTYPE::text: agk::DeleteText(ID1); break;
	case AGK_Delete::OBJTYPE::button: agk::DeleteVirtualButton(ID1); break;
	case AGK_Delete::OBJTYPE::sprite: agk::DeleteSprite(ID1); break;
	}
}