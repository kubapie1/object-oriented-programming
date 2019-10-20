#include "TestIncludes.h"
#include "TextWrapper.h"

TEST(TextWrapper, CreateInstance)
{
    auto wrapper = TextWrapper{};
}

TEST(TextWrapper, HasColumnsGetter)
{
    auto wrapper = TextWrapper{};

    EXPECT_EQ(10, wrapper.getColumns());
}

TEST(TextWrapper, HasInitializeConstructor)
{
    auto wrapper = TextWrapper{8};

    EXPECT_EQ(8, wrapper.getColumns());
}

TEST(TextWrapper, StringReceiving)
{
    auto wrapper = TextWrapper{};
    std::string testText = "wwww";

    wrapper.textAssign(testText);
    EXPECT_EQ(testText, wrapper.getOurText());
}

TEST(TextWrapper, StringSubtraction)
{
    auto wrapper = TextWrapper{5};
    std::string testText = "To test testu funkcji.";
    wrapper.textAssign( testText );
    wrapper.stringSubtraction();
    EXPECT_EQ("To t-\nest\ntestu\nfunk-\ncji.",wrapper.getOurText());
}