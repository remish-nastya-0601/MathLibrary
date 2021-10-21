#include "pch.h"
#include <stdio.h>
#include <windows.h>  
//В нем содержится описание
// типов APIENTRY, HINSTANCE и др.

// Объявляем функцию DllMain
BOOL APIENTRY DllMain(HINSTANCE hinstDLL,
    DWORD fdwReason, LPVOID lpvReserved)
{

    switch (fdwReason)      // Дерево разбора уведомлений
    {
    case DLL_PROCESS_ATTACH: // Подключение DLL
        printf("Подключение DLL\n");
        // Получение описателя экземпляра DLL
        printf("HINSTANCE = %x\n", hinstDLL);

        if (lpvReserved)  // Определение способа загрузки
            printf("DLL загружена с неявной компоновкой \n");
        else
            printf("DLL загружена с явной компоновкой \n");
        return 1; // успешная инициализация

    case DLL_PROCESS_DETACH: // Отключение DLL
      // Здесь – освобождаем память, закрываем
      // файлы и т.д.
        printf("Отключение DLL\n");
        break;

    case DLL_THREAD_ATTACH: // Уведомление о новом потоке 
      // Здесь – если надо переходим на
      // многопоточный режим работы с
      // использованием средств синхронизации
      // таких как критическая секция, мутанты,
      // семафоры и т.д.
        printf("Создание процессом нового потока\n");
        break;

    case DLL_THREAD_DETACH:
        //Уведомление о завершении потока
      // Здесь – если надо освобождаем все ресурсы, 
      // вязанные с завершившимся потоком. Какой именно
      // поток завершился можно узнать просмотром списка
      // потоков средствами TOOLHELP32
        printf("Завершение потока\n");
        break;

    }
    return TRUE;    // Код возврата игнорируется
}