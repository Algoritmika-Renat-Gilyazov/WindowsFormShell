#pragma once
// Visual Studio автоматически создает макрос <ИМЯ_ПРОЕКТА>_EXPORTS при создании DLL.
// Либо добавьте MYLIB_EXPORTS в: Свойства проекта DLL -> C/C++ -> Preprocessor -> Preprocessor Definitions
#ifdef MYLIB_EXPORTS
#define MYLIB_API __declspec(dllexport)
#else
#define MYLIB_API __declspec(dllimport)
#endif

// Подавляем предупреждение C4251 для STL-полей (безопасно при одинаковых настройках сборки)
#pragma warning(disable: 4251)