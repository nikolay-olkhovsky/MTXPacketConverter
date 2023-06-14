#pragma once
class CMTXFilename
{
public:
	static const char* tag;
	static const char* suffixA;
	static const char* suffixb;
	static const char* suffixc;
	static const char* suffixlo;
	static const char* suffixhi;
	static const char* suffixtr;
	static const char* extension;
	static const char* pack;
	static const char* lpp_filename;

	static const char* folderPrefix;

	static const char* A(const char* folder = "", bool withPack = false);
	static const char* b(const char* folder = "", bool withPack = false);
	static const char* c(const char* folder = "", bool withPack = false);
	static const char* lo(const char* folder = "", bool withPack = false);
	static const char* hi(const char* folder = "", bool withPack = false);
	static const char* tr(const char* folder = "", bool withPack = false);
	static const char* lpp(const char* folder = "", bool withPack = false);
	static const char* folderName(unsigned number);

};

