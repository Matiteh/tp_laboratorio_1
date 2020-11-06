int controller_loadFromText(char* path ,char* pathId ,LinkedList* pArrayListEmployee ,int* idMax);
int controller_loadFromBinary(char* path ,char* pathId ,LinkedList* pArrayListEmployee ,int* idMax);
int controller_addEmployee(LinkedList* pArrayListEmployee ,int* idMax);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee,int* idMax);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path,char* pathIdMax, LinkedList* pArrayListEmployee ,int* idMax);
int controller_saveAsBinary(char* path,char* pathIdMax, LinkedList* pArrayListEmployee ,int* idMax);


