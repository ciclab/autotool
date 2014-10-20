#ifdef _FILE_UITLITY_H_
#define _FILE_UITLITY_H_

enum EFileType{H_FILE, CPP_FILE};

class FileUtility
{
 public:
  // generate .h or .cpp file given fileName and file content
  static void GenFile(const string& fileName,
		      cosnt string& content
		      EFileType fileType);

  static void AppendFile(const string& fileName,
			 const string& content,
			 EfileType fileType);
};

#endif
