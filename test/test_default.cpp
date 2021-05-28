#pragma once
#include <gtest/gtest.h>

#include"roman.hpp"

TEST(Roman,true)
{
    EXPECT_EQ(true,true);
}

TEST(Roman,perevod_roman_in_arabic_correct)
{
    std::string s="VIII";

    Roman_Arabic r;
    int z=r.perevod_roman_in_arabic(s);

    EXPECT_EQ(z,8);
}

TEST(Roman,perevod_arabic_in_roman_correct)
{
    Roman_Arabic r;
    std::string s = r.perevod_arabic_in_roman(338); 
    EXPECT_EQ(s,"CCCXXXVIII");
}

TEST(Roman,wrong1)
{
    Roman_Arabic r;
    ASSERT_ANY_THROW(r.perevod_roman_in_arabic("IIII"));
}
TEST(Roman,wrong2)
{
    Roman_Arabic r;
    ASSERT_ANY_THROW(r.perevod_roman_in_arabic("IIX"));
}
TEST(Roman,wrong3)
{
    Roman_Arabic r;
    ASSERT_ANY_THROW(r.perevod_roman_in_arabic("IC"));
}
TEST(Roman,wrong4)
{
    Roman_Arabic r;
    ASSERT_ANY_THROW(r.perevod_roman_in_arabic("CVIC"));
}
TEST(Roman,wrong5)
{
   Roman_Arabic r;
   ASSERT_ANY_THROW(r.perevod_arabic_in_roman(5000));
}