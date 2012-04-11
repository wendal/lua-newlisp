
#define UINT unsigned long 
#define MAX_STRING 2048
#define MAX_FILE_BUFFER 102400

typedef struct
	{
	int handle;
	char *ptr;
	char *buffer;
	size_t position;
	size_t size;
	} STREAM;

typedef struct tagSYMBOL
	{
	short int flags;
	short int color;
	char * name;
	UINT contents; 
	struct tagSYMBOL * context;
	struct tagSYMBOL * parent;
	struct tagSYMBOL * left;
	struct tagSYMBOL * right;   
	} SYMBOL;

typedef struct 
	{
	UINT type;
	void * next;
	UINT aux;
	UINT contents;
	} CELL;



char * newlispEvalStr(char * cmd);

CELL * loadFile(char * fileName, UINT offset, int encryptFlag, SYMBOL * context);
CELL * evaluateStream(STREAM * stream, UINT outDevice, int flag);
void printCell(CELL * cell, UINT printFlag, UINT device);

int makeStreamFromFile(STREAM * stream, char * fileName, size_t size, size_t offset);
int makeStreamFromString(STREAM * stream, char * str);
