//
// Created by 이민철 on 2020/11/17.
//


#include "cld3.h"
#include "nnet_language_identifier.h"

using chrome_lang_id::NNetLanguageIdentifier;

Result lang_detect(const char *text) {
    NNetLanguageIdentifier lang_id(/*min_num_bytes=*/0,
            /*max_num_bytes=*/1000);
    auto result = lang_id.FindLanguage(text);

    Result out;
    out.language = new char[result.language.length() + 1];
    strcpy(out.language, result.language.c_str());
    out.len_language = result.language.length();
    return out;
}