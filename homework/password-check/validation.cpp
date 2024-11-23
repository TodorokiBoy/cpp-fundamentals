#include "validation.hpp"
#include <algorithm>
#include <cctype>

std::string getErrorMessage(ErrorCode error) {
    switch (error) {
    case ErrorCode::Ok:
        return "Ok";

    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password needs to have at least nine characters";

    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs to have at least one number";

    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs to have at least one special character";

    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs to have at least one uppercase letter";

    case ErrorCode::PasswordsDoNotMatch:
        return "Passwords do not match";
    }
    return "Undefined error";
}

bool doPasswordsMatch(std::string password1, std::string password2) {
    return password1 == password2;
}

ErrorCode checkPasswordRules(std::string password) {
    if (password.length() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if (!std::any_of(password.begin(), password.end(), [](unsigned char c) { return std::isdigit(c); })) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (!std::any_of(password.begin(), password.end(), [](unsigned char c) { return std::ispunct(c); })) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (!std::any_of(password.begin(), password.end(), [](unsigned char c) { return std::isupper(c); })) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string password1, std::string password2) {
    if (doPasswordsMatch(password1, password2)) {
        return checkPasswordRules(password1);
    }
    return ErrorCode::PasswordsDoNotMatch;
}