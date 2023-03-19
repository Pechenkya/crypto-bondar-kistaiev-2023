#include <fstream>
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

wchar_t convert_in_cyrilic(wchar_t c)
{
    if ((c >= L'а' && c <= L'я')) 
    {
        return c;
    }
    else if (c >= L'А' && c <= L'Я') 
    {
        return c - 0x20;
    }
    else if(c == L'ё' || c == L'Ё')
    {
        return L'е';
    }
        
    return L' ';
}

std::wstring preprocess_text(const std::string& file_name)
{
    std::wifstream in(file_name);
    in.imbue(std::locale(in.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));
    std::wstring text_spaced;

    while(!in.eof())
    {
        wchar_t c1;
        in >> c1;
        wchar_t c2 = convert_in_cyrilic(c1);
        text_spaced.push_back(c2);
    }
    std::wstring text_despaced;

    bool space_flag = false;
    for(auto mobil : text_spaced)
    {
        if (mobil == L' ')
        {
            if(!space_flag)
            {
                text_despaced.push_back(L' ');
                space_flag = true;
            }
        }
        else
        {
            text_despaced.push_back(mobil);
            space_flag = false;
        }
        
    }

    in.close();

    return text_despaced;
}

int main()
{
    std::wofstream out("preproc.txt");
    std::wstring text = preprocess_text("girkin_crying.txt");

    out << text;

    out.close(); 
}
