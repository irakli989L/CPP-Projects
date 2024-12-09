cmake_minimum_required(VERSION 3.30)
project(BankingProgram)

set(CMAKE_CXX_STANDARD 20)

add_executable(BankingProgram main.cpp
        Account.h
        SavingsAccount.h
        CurrentAccount.h
)
