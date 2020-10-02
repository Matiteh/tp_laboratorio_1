typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
}eEmployee;

int initEmployees(eEmployee list[], int tam);

int altaEmpleado(eEmployee list[], int tam, int initID);

int addEmployee(eEmployee list[], int tam, int initID);

int buscarLibre(eEmployee list[], int tam);

int menuPrincipal(char mensaje[]);

int imprimirEmpleados(eEmployee list[], int tam, int flag);

int printEmpleados(eEmployee list[], int tam, int flag);

int salariosEmpleadosTotal(eEmployee list[], int tam);

int salariosEmpleadosPromedio(eEmployee list[], int tam);

int flagAlta(int flag);

int bajaEmpleado(eEmployee list[], int tam,int flag);

int removeEmployee(eEmployee list[], int tam, int id);

int findEmployeeById(eEmployee list[], int tam, int id);

int modifyEmployees(eEmployee list[],int tam,int id);

int modificarEmpleado(eEmployee list[], int tam,int flag);

int validacionSector(int aux);

float validacionSalario(float aux);

char* validacionNombrecompleto(char nombreApellido[]);

int ordenamientoEmpleados(eEmployee list[], int tam, int orden);
