// --- MultiMatrix.cpp
// расстановка скобок (рекурсия)

#include <memory.h>
#include "MultyMatrix.h"

#define INFINITY 0x7fffffff
#define NINFINITY 0x80000000

// Функция для вычисления оптимального значения умножения матриц с использованием рекурсии
int OptimalM(int i, int j, int n, const int c[], int* s)
{
    // Макрос для доступа к элементам массива s
#define OPTIMALM_S(x1,x2)  (s[(x1-1)*n+x2-1])  

    int o = INFINITY;  // Минимальное значение для умножения матриц
    int bo = INFINITY; // Временное значение для текущего расчета

    // Если i < j, то можно делать рекурсивный вызов
    if (i < j)
    {
        for (int k = i; k < j; k++)
        {
            // Рекурсивно вызываем функцию OptimalM для подматрицы i..k и k+1..j
            bo = OptimalM(i, k, n, c, s) +
                OptimalM(k + 1, j, n, c, s) + c[i - 1] * c[k] * c[j];

            // Если текущее значение bo меньше минимального значения o,
            // обновляем минимальное значение и запоминаем позицию k
            if (bo < o)
            {
                o = bo;
                OPTIMALM_S(i, j) = k;
            }
        }
    }
    else
    {
        // Если i >= j, то значение равно 0, так как нет матриц для умножения
        o = 0;
    }

    return o;

    // Убираем определение макроса
#undef OPTIMALM_S
};

// --- MultyMatrix.cpp (продолжение)
// расстановка скобок (динамическое программирование)
int OptimalMD(int n, const int c[], int* s)
{
    // Макросы для доступа к элементам массивов s и M
#define OPTIMALM_S(x1,x2)  (s[(x1-1)*n+x2-1]) 
#define OPTIMALM_M(x1,x2)  (M[(x1-1)*n+x2-1])

    int* M = new int[n * n];  // Массив для хранения промежуточных значений
    int j = 0, q = 0;

    // Инициализация диагональных элементов M как 0
    for (int i = 1; i <= n; i++)
    {
        OPTIMALM_M(i, i) = 0;
    }

    // Заполнение массива M для различных длин подматриц
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            OPTIMALM_M(i, j) = INFINITY;  // Инициализация текущего значения как бесконечность

            // Перебор возможных разбиений подматрицы i..j
            for (int k = i; k <= j - 1; k++)
            {
                q = OPTIMALM_M(i, k) + OPTIMALM_M(k + 1, j) + c[i - 1] * c[k] * c[j];

                // Если текущее значение q меньше текущего значения M(i, j),
                // обновляем M(i, j) и запоминаем позицию k
                if (q < OPTIMALM_M(i, j))
                {
                    OPTIMALM_M(i, j) = q;
                    OPTIMALM_S(i, j) = k;
                }
            }
        }
    }

    int optimalValue = OPTIMALM_M(1, n);  // Оптимальное значение умножения матриц

    delete[] M;  // Освобождение памяти, выделенной для массива M

    return optimalValue;

    // Убираем определения макросов
#undef OPTIMALM_M
#undef OPTIMALM_S
};