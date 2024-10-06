#ifdef CHANGED
#include "copyright.h"
#include "system.h"
#include "consoledriver.h"
#include "synch.h"
#include "utils.h"
static Semaphore *readAvail;
static Semaphore *writeDone;
static void ReadAvailHandler(void *arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void *arg) { (void) arg; writeDone->V(); }

ConsoleDriver::ConsoleDriver(const char *in, const char *out)
{
    readAvail = new Semaphore("read avail", 0);
    writeDone = new Semaphore("write done", 0);
    console = new Console(in, out, ReadAvailHandler, WriteDoneHandler, NULL);
}

ConsoleDriver::~ConsoleDriver()
{
    delete console;
    delete writeDone;
    delete readAvail;
}

void ConsoleDriver::PutChar(int ch)
{
    console->TX (ch);      // echo it!
    writeDone->P ();       // wait for write to finish
}
int ConsoleDriver::GetChar()
{
    readAvail->P ();        // wait for character to arrive
    int redChar = console->RX ();
    return redChar == EOF ? 0 : redChar ;
}
void ConsoleDriver::PutString(const char *s)
{
    if(s == NULL){
        DEBUG('s',"tried to putstring a null string");
    }
    while (*s != '\0')
    {
        PutChar(*s);
        s++;
    }
}
void ConsoleDriver::GetString(char *s, int n)
{
 if (s == NULL){
    DEBUG('s',"tried to get a null string");
 }
 for (int i = 0; i<n-1; i++){
    int c = GetChar();
    if (c == EOF){
        break;
    }
    if (c == '\n'){
        *s = c;
        break;
    }
    *s = c;
    s++;
 }
 *s='\0';
}

void ConsoleDriver::PutInt(int n)
{
    char* buffer = (char*)malloc(sizeof(char)*MAX_INT_SIZE);
    snprintf(buffer, MAX_INT_SIZE, "%d", n);
    PutString(buffer);
    free(buffer);
}

void ConsoleDriver::GetInt(int *n)
{
    char* buffer = (char*)malloc(sizeof(char)*MAX_INT_SIZE);
    GetString(buffer, MAX_INT_SIZE);
    if (buffer[0] != '-'){
        buffer[MAX_INT_SIZE-2] = '\0'; // If the string is positive we need to forgot the last digit
    }
    sscanf(buffer, "%d", n);
    free(buffer);
}

#endif // CHANGED