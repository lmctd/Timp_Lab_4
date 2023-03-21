/**  @file
*   @author Бубнов В.А.
*   @version 0.1
*   @date 21.02.2023
*   @brief Заголовочный файл для модуля modAlphaCipher
*/


#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>
#include <codecvt>
#include <iostream>
#include <cctype>
using namespace std;

/** @class modAlphaCipher
 * @author Бубнов В.А.
 * @date 21.02.2023
 * @file modAlphaCipher.h
 * @brief Шифрование методом Гронсфельда
 * @detalies Для зашифрования и расшифрования сообщения предназначены методы encrypt и decrypt. Текст на обработку передается в качестве параметра.
 * @warnings Реализация только для русского языка!
 */
class modAlphaCipher
{
private:
    std::string numAlpha = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
    std::string numalpha = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(numAlpha);
    std::wstring wa = codec.from_bytes(numalpha);
    std::map <char,int> alphaNum; //ассоциативный массив "номер по символу"
    std::vector <int> key; //ключ
    std::vector<int> convert(const std::string& s); //преобразование строка-вектор

    std::string convert(const std::vector<int>& v); //преобразование вектор-строка
    /** @brief Метод класса, проверяющий текс на валидность
     * @param [in] s Текст на русском языке
     * @return result
     */
    std::string getValidOpenText(const std::string & s);
    /** @brief Метод класса, проверяющий расшифрованный текст на валидность
     * @param [in] s Зашифрованный текст на русском языке
     * @return result
     */
    std::string getValidCipherText(const std::string & s);
    /** @brief Метод класса, проверяющий ключ на валидность
     * @param [in] s Ключ
     * @return result
     */
    std::string getValidKey(const std::string & s);
public:
    modAlphaCipher()=delete; //запретим конструктор без параметров
    /** @brief Конструктор для создания объекта, хранящего в себе ключ шифрования
     * @param [in] text Открытый текст на русском языке
     * @warnings Текс не должен быть пустоц строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     */
    modAlphaCipher(const std::string& skey); //конструктор для установки ключа
    /** @brief Зашифрование
     * @param [in] text Открытый текст на русском языке
     * @warnings Текс не должен быть пустоц строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     * @return result Зашифрованный текст
     */
    std::string encrypt(const std::string& open_text); //зашифрование
    /** @brief Зашифрование
     * @param [in] text Зашифрованный текст на русском языке
     * @warnings Текст не должен быть пустоц строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     * @return result Зашифрованный текст
     */
    std::string decrypt(const std::string& cipher_text);//расшифрование
};

class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
