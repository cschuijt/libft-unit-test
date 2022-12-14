/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:48:56 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/10/15 21:46:56 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "munit.h"
#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Toggle part 1, part 2 or the bonus part on or off with these globals
#if !defined(TEST_PART_1)
# define TEST_PART_1 true
#endif

#if !defined(TEST_PART_2)
# define TEST_PART_2 true
#endif

#if !defined(TEST_BONUS)
# define TEST_BONUS false
#endif

// Normalization function for *cmp function returns, whether these return
// -1/0/1 or larger numbers is implementation specific so we'll accept
// anything along those lines from both stdlib and libft
int	ft_norm(int i)
{
	if (i > 0)
		return (1);
	if (i < 0)
		return (-1);
	return (0);
}

#if (TEST_PART_1 == true)
MunitResult	ft_atoi_test(const MunitParameter params[], void *data)
{
	munit_assert_int(atoi("0"), ==, ft_atoi("0"));
	munit_assert_int(atoi("-5"), ==, ft_atoi("-5"));
	munit_assert_int(atoi("-----10"), ==, ft_atoi("-----10"));
	munit_assert_int(atoi("----805"), ==, ft_atoi("----805"));
	munit_assert_int(atoi("1001   23432"), ==, ft_atoi("1001   23432"));
	munit_assert_int(atoi(""), ==, ft_atoi(""));
	munit_assert_int(atoi("2147483647"), ==, ft_atoi("2147483647"));
	munit_assert_int(atoi("2147483648"), ==, ft_atoi("2147483648"));
	munit_assert_int(atoi("-2147483648"), ==, ft_atoi("-2147483648"));
	munit_assert_int(atoi("-2147483649"), ==, ft_atoi("-2147483649"));
	munit_assert_int(atoi("    \n666"), ==, ft_atoi("    \n666"));
	munit_assert_int(atoi("fjkdffd444"), ==, ft_atoi("fjkdffd444"));
	munit_assert_int(atoi("   54.gkrrgkr"), ==, ft_atoi("   54.gkrrgkr"));
	munit_assert_int(atoi("+-+--+46"), ==, ft_atoi("+-+--+46"));
	munit_assert_int(atoi("+46"), ==, ft_atoi("+46"));
	munit_assert_int(atoi("asdf"), ==, ft_atoi("asdf"));
	munit_assert_int(atoi("8f7d2kx7"), ==, ft_atoi("8f7d2kx7"));
	munit_assert_int(atoi("-"), ==, ft_atoi("-"));
	munit_assert_int(atoi("-0"), ==, ft_atoi("-0"));
	munit_assert_int(atoi("+"), ==, ft_atoi("+"));
	munit_assert_int(atoi("+0"), ==, ft_atoi("+0"));
	munit_assert_int(atoi("4--"), ==, ft_atoi("4--"));
	return (MUNIT_OK);
}

MunitResult	ft_strlen_test(const MunitParameter params[], void *data)
{
	munit_assert_int(strlen("asdf"), ==, ft_strlen("asdf"));
	munit_assert_int(strlen("   "), ==, ft_strlen("   "));
	munit_assert_int(strlen(""), ==, ft_strlen(""));
	munit_assert_int(strlen("asd\nfds"), ==, ft_strlen("asd\nfds"));
	munit_assert_int(strlen("1234567890"), ==, ft_strlen("1234567890"));
	munit_assert_int(strlen("a slightly longer string of words"), ==, ft_strlen("a slightly longer string of words"));
	munit_assert_int(strlen("asdf\0a1234"), ==, ft_strlen("asdf\0a1234"));
	return (MUNIT_OK);
}

MunitResult	ft_strchr_test(const MunitParameter params[], void *data)
{
	char	*str, *emptystr, *str2, *str3;

	str = "Hello world! This is a very long str1ng w1th funny cha\nracters.\0z";
	emptystr = "";
	str2 = "teste";
	munit_assert_ptr_equal(strchr(str, 'w'), ft_strchr(str, 'w'));
	munit_assert_ptr_equal(strchr(str, 'e'), ft_strchr(str, 'e'));
	munit_assert_ptr_equal(strchr(str, 'H'), ft_strchr(str, 'H'));
	munit_assert_ptr_equal(strchr(str, 'h'), ft_strchr(str, 'h'));
	munit_assert_ptr_equal(strchr(str, '!'), ft_strchr(str, '!'));
	munit_assert_ptr_equal(strchr(str, '1'), ft_strchr(str, '1'));
	munit_assert_ptr_equal(strchr(str, '.'), ft_strchr(str, '.'));
	munit_assert_ptr_equal(strchr(str, '\0'), ft_strchr(str, '\0'));
	munit_assert_ptr_equal(strchr(str, 'x'), ft_strchr(str, 'x'));
	munit_assert_ptr_equal(strchr(str, '\n'), ft_strchr(str, '\n'));
	munit_assert_ptr_equal(strchr(str, 'z'), ft_strchr(str, 'z'));
	munit_assert_ptr_equal(strchr(str2, 'e'), ft_strchr(str2, 'e'));
	munit_assert_ptr_equal(strchr(emptystr, 'z'), ft_strchr(emptystr, 'z'));
	munit_assert_ptr_equal(strchr(emptystr, '\0'), ft_strchr(emptystr, '\0'));
	return (MUNIT_OK);
}

MunitResult	ft_strrchr_test(const MunitParameter params[], void *data)
{
	char	*str;
	char	*emptystr;

	str = "Hello world! This is a very long str1ng w1th funny cha\nracters.\0z";
	emptystr = "";
	munit_assert_ptr_equal(strrchr(str, 'w'), ft_strrchr(str, 'w'));
	munit_assert_ptr_equal(strrchr(str, 'e'), ft_strrchr(str, 'e'));
	munit_assert_ptr_equal(strrchr(str, 'H'), ft_strrchr(str, 'H'));
	munit_assert_ptr_equal(strrchr(str, 'h'), ft_strrchr(str, 'h'));
	munit_assert_ptr_equal(strrchr(str, '!'), ft_strrchr(str, '!'));
	munit_assert_ptr_equal(strrchr(str, '1'), ft_strrchr(str, '1'));
	munit_assert_ptr_equal(strrchr(str, '.'), ft_strrchr(str, '.'));
	munit_assert_ptr_equal(strrchr(str, '\0'), ft_strrchr(str, '\0'));
	munit_assert_ptr_equal(strrchr(str, 'x'), ft_strrchr(str, 'x'));
	munit_assert_ptr_equal(strrchr(str, '\n'), ft_strrchr(str, '\n'));
	munit_assert_ptr_equal(strrchr(str, 'z'), ft_strrchr(str, 'z'));
	munit_assert_ptr_equal(strrchr(emptystr, 'z'), ft_strrchr(emptystr, 'z'));
	munit_assert_ptr_equal(strrchr(emptystr, '\0'), ft_strrchr(emptystr, '\0'));
	return (MUNIT_OK);
}

MunitResult	ft_strdup_test(const MunitParameter params[], void *data)
{
	char	*str;

	munit_assert_string_equal(strdup("asdf"), ft_strdup("asdf"));
	munit_assert_string_equal(strdup("tjt\newwer\f123"), ft_strdup("tjt\newwer\f123"));
	munit_assert_string_equal(strdup("!"), ft_strdup("!"));
	munit_assert_string_equal(strdup(""), ft_strdup(""));
	munit_assert_string_equal(strdup("qwe\0rty"), ft_strdup("qwe\0rty"));
	munit_assert_string_equal(strdup("This is a longer string."), ft_strdup("This is a longer string."));
	munit_assert_string_equal(strdup("\0"), ft_strdup("\0"));

	munit_assert_string_equal("asdf", ft_strdup("asdf"));
	// Ensure that ft_strdup isn't just returning a pointer to the original xd
	str = "hoi";
	munit_assert_ptr_not_equal(str, ft_strdup(str));
	return (MUNIT_OK);
}

MunitResult	ft_memset_test(const MunitParameter params[], void *data)
{
	char	*str1, *str2;
	char	*pnt1, *pnt2;

	str1 = malloc(sizeof(char) * 30);
	str2 = malloc(sizeof(char) * 30);
	pnt1 = memset(str1, 49, 8);
	pnt2 = ft_memset(str2, 49, 8);
	munit_assert_memory_equal(8, str1, str2);
	munit_assert_memory_equal(8, pnt1, pnt2);
	munit_assert_ptr_equal(str2, pnt2);
	memset(str1, 72, 20);
	ft_memset(str2, 72, 20);
	munit_assert_memory_equal(20, str1, str2);
	memset(str1, 80, 3);
	ft_memset(str2, 80, 3);
	munit_assert_memory_equal(20, str1, str2);
	memset(str1 + 10, 90, 5);
	ft_memset(str2 + 10, 90, 5);
	munit_assert_memory_equal(20, str1, str2);
	pnt1 = memset(str1, 100, (0));
	pnt2 = ft_memset(str2, 100, 0);
	munit_assert_memory_equal(20, str1, str2);
	munit_assert_ptr_equal(pnt1, str1);
	munit_assert_ptr_equal(pnt2, str2);
	free(str1);
	free(str2);
	return (MUNIT_OK);
}

MunitResult	ft_bzero_test(const MunitParameter params[], void *data)
{
	char	*str1, *str2;

	str1 = malloc(sizeof(char) * 30);
	str2 = malloc(sizeof(char) * 30);
	memset(str1, 80, 22);
	memset(str2, 80, 22);
	bzero(str1, (0));
	ft_bzero(str2, 0);
	munit_assert_memory_equal(20, str1, str2);
	bzero(str1, 8);
	ft_bzero(str2, 8);
	munit_assert_memory_equal(8, str1, str2);
	bzero(str1, 3);
	ft_bzero(str2, 3);
	munit_assert_memory_equal(20, str1, str2);
	bzero(str1 + 10, 5);
	ft_bzero(str2 + 10, 5);
	munit_assert_memory_equal(20, str1, str2);
	bzero(str1, 20);
	ft_bzero(str2, 20);
	munit_assert_memory_equal(20, str1, str2);
	free(str1);
	free(str2);
	return (MUNIT_OK);
}

MunitResult	ft_memcpy_test(const MunitParameter params[], void *data)
{
	char	*str, *str2, *pnt1, *pnt2;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 30);
	str2 = malloc(sizeof(char) * 30);
	while (i < 30)
	{
		str[i] = 94 + i;
		str2[i] = 94 + i;
		i++;
	}
	munit_assert_memory_equal(30, str, str2);
	pnt1 = memcpy(str + 10, str, 3);
	pnt2 = ft_memcpy(str2 + 10, str2, 3);
	munit_assert_memory_equal(30, str, str2);
	pnt2 = ft_memcpy(str + 10, str, 3);
	munit_assert_ptr_equal(pnt1, pnt2);
	memcpy(str + 20, str + 4, 0);
	ft_memcpy(str2 + 20, str2 + 4, 0);
	munit_assert_memory_equal(30, str, str2);
	memcpy(str + 3, str + 18, 10);
	ft_memcpy(str2 + 3, str2 + 18, 10);
	munit_assert_memory_equal(30, str, str2);
	free(str);
	free(str2);
	return (MUNIT_OK);
}

MunitResult	ft_memmove_test(const MunitParameter params[], void *data)
{
	char	*str, *str2, *pnt1, *pnt2;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 30);
	str2 = malloc(sizeof(char) * 30);
	while (i < 30)
	{
		str[i] = 94 + i;
		str2[i] = 94 + i;
		i++;
	}
	munit_assert_memory_equal(30, str, str2);
	pnt1 = memmove(str + 10, str, 3);
	pnt2 = ft_memmove(str2 + 10, str2, 3);
	munit_assert_memory_equal(30, str, str2);
	pnt2 = ft_memmove(str + 10, str, 3);
	munit_assert_ptr_equal(pnt1, pnt2);
	memmove(str + 20, str + 4, 0);
	ft_memmove(str2 + 20, str2 + 4, 0);
	munit_assert_memory_equal(30, str, str2);
	memmove(str + 3, str + 18, 10);
	ft_memmove(str2 + 3, str2 + 18, 10);
	munit_assert_memory_equal(30, str, str2);
	i = 0;
	while (i < 30)
	{
		str[i] = 94 + i;
		str2[i] = 94 + i;
		i++;
	}
	munit_assert_memory_equal(30, str, str2);
	memmove(str, str, 25);
	ft_memmove(str2, str2, 25);
	munit_assert_memory_equal(30, str, str2);
	memmove(str + 8, str, 10);
	ft_memmove(str2 + 8, str2, 10);
	munit_assert_memory_equal(30, str, str2);
	memmove(str + 19, str + 15, 10);
	ft_memmove(str2 + 19, str2 + 15, 10);
	munit_assert_memory_equal(30, str, str2);
	free(str);
	free(str2);
	return (MUNIT_OK);
}

MunitResult	ft_strlcpy_test(const MunitParameter params[], void *data)
{
	char	*str1, *str2, *str3;

	str1 = "asdfgh \n535tt\0dsffd";
	str2 = calloc(sizeof(char), 30);
	str3 = calloc(sizeof(char), 30);
	munit_assert_int(strlcpy(str2, str1, 5), ==, ft_strlcpy(str3, str1, 5));
	munit_assert_string_equal(str2, str3);
	munit_assert_memory_equal(30, str2, str3);
	memset(str2, 80, 30);
	memset(str3, 80, 30);
	munit_assert_int(strlcpy(str2, str1, 14), ==, ft_strlcpy(str3, str1, 14));
	munit_assert_string_equal(str2, str3);
	munit_assert_memory_equal(30, str2, str3);
	memset(str2, 80, 30);
	memset(str3, 80, 30);
	munit_assert_int(strlcpy(str2, str1, 19), ==, ft_strlcpy(str3, str1, 19));
	munit_assert_string_equal(str2, str3);
	munit_assert_memory_equal(30, str2, str3);
	memset(str2, 80, 30);
	memset(str3, 80, 30);
	munit_assert_int(strlcpy(str2, str1, 20), ==, ft_strlcpy(str3, str1, 20));
	munit_assert_string_equal(str2, str3);
	munit_assert_memory_equal(30, str2, str3);
	memset(str2, 80, 30);
	memset(str3, 80, 30);
	munit_assert_int(strlcpy(str2, str1, 400), ==, ft_strlcpy(str3, str1, 400));
	munit_assert_string_equal(str2, str3);
	munit_assert_memory_equal(30, str2, str3);
	memset(str2, 80, 30);
	memset(str3, 80, 30);
	munit_assert_int(strlcpy(str2, str1, 0), ==, ft_strlcpy(str3, str1, 0));
	munit_assert_string_equal(str2, str3);
	munit_assert_memory_equal(30, str2, str3);
	memset(str2, 80, 30);
	memset(str3, 80, 30);
	munit_assert_int(strlcpy(str2, str1, 1), ==, ft_strlcpy(str3, str1, 1));
	munit_assert_string_equal(str2, str3);
	munit_assert_memory_equal(30, str2, str3);
	free(str2);
	free(str3);
	return (MUNIT_OK);
}

MunitResult	ft_strlcat_test(const MunitParameter params[], void *data)
{
	char	*str1, *str2, *str3, *str4, *str5;

	str1 = "qwerty \n535tt\0dsffd"; // 13
	str2 = calloc(sizeof(char), 30);
	str3 = calloc(sizeof(char), 30);
	str4 = calloc(sizeof(char), 10);
	str5 = calloc(sizeof(char), 10);
	strlcpy(str2, "asdfg", 6);
	strlcpy(str3, "asdfg", 6);
	munit_assert_int(strlcat(str2, str1, 5), ==, ft_strlcat(str3, str1, 5));
	munit_assert_string_equal(str2, str3);
	munit_assert_memory_equal(30, str2, str3);
	memset(str2, 80, 30);
	memset(str3, 80, 30);
	strlcpy(str2, "asdfg", 6);
	strlcpy(str3, "asdfg", 6);
	munit_assert_int(strlcat(str2, str1, 14), ==, ft_strlcat(str3, str1, 14));
	munit_assert_string_equal(str2, str3);
	munit_assert_memory_equal(30, str2, str3);
	memset(str2, 80, 30);
	memset(str3, 80, 30);
	strlcpy(str2, "asdfg", 3);
	strlcpy(str3, "asdfg", 3);
	munit_assert_int(strlcat(str2, str1, 19), ==, ft_strlcat(str3, str1, 19));
	munit_assert_string_equal(str2, str3);
	munit_assert_memory_equal(30, str2, str3);
	memset(str2, 80, 30);
	memset(str3, 80, 30);
	strlcpy(str2, "asdfg", 6);
	strlcpy(str3, "asdfg", 6);
	munit_assert_int(strlcat(str2, str1, 20), ==, ft_strlcat(str3, str1, 20));
	munit_assert_string_equal(str2, str3);
	munit_assert_memory_equal(30, str2, str3);
	memset(str2, 80, 30);
	memset(str3, 80, 30);
	strlcpy(str2, "asdfg", 6);
	strlcpy(str3, "asdfg", 6);
	munit_assert_int(strlcat(str2, str1, 0), ==, ft_strlcat(str3, str1, 0));
	munit_assert_string_equal(str2, str3);
	munit_assert_memory_equal(30, str2, str3);
	memset(str2, 80, 30);
	memset(str3, 80, 30);
	munit_assert_int(strlcat(str2, str1, 20), ==, ft_strlcat(str3, str1, 20));
	munit_assert_string_equal(str2, str3);
	munit_assert_memory_equal(30, str2, str3);
	memset(str4, 80, 10);
	memset(str5, 80, 10);
	strlcpy(str4, "asdfg", 6);
	strlcpy(str5, "asdfg", 6);
	munit_assert_int(strlcat(str4, str1, 2), ==, ft_strlcat(str5, str1, 2));
	munit_assert_string_equal(str4, str5);
	munit_assert_memory_equal(10, str4, str5);
	memset(str4, 80, 10);
	memset(str5, 80, 10);
	strlcpy(str4, "asdfg", 6);
	strlcpy(str5, "asdfg", 6);
	munit_assert_int(strlcat(str4, str1, 10), ==, ft_strlcat(str5, str1, 10));
	munit_assert_string_equal(str4, str5);
	munit_assert_memory_equal(10, str4, str5);
	free(str2);
	free(str3);
	char *str6 = ft_calloc(sizeof(char), 10);
	memset(str6, 'P', 10);
	munit_assert_int(ft_strlcat(str6, "1234", 5), ==, 9);
	munit_assert_int(ft_strlcat(str6, "1234", 10), ==, 14);
	munit_assert_memory_equal(10, str6, "PPPPPPPPPP");
	ft_bzero(str6, 10);
	ft_strlcat(str6, "1234", 0);
	munit_assert_string_equal(str6, "");
	free(str6);
	return (MUNIT_OK);
}

MunitResult	ft_strncmp_test(const MunitParameter params[], void *data)
{
	munit_assert_int(ft_norm(strncmp("asdf", "asdf", 3)), ==, ft_norm(ft_strncmp("asdf", "asdf", 3)));
	munit_assert_int(ft_norm(strncmp("asdf", "asdf", 5)), ==, ft_norm(ft_strncmp("asdf", "asdf", 5)));
	munit_assert_int(ft_norm(strncmp("asdf", "asdf", 30)), ==, ft_norm(ft_strncmp("asdf", "asdf", 30)));
	munit_assert_int(ft_norm(strncmp("asdF", "asdf", 3)), ==, ft_norm(ft_strncmp("asdF", "asdf", 3)));
	munit_assert_int(ft_norm(strncmp("asdF", "asdf", 4)), ==, ft_norm(ft_strncmp("asdF", "asdf", 4)));
	munit_assert_int(ft_norm(strncmp("AsdF", "asdf", 0)), ==, ft_norm(ft_strncmp("AsdF", "asdf", 0)));
	munit_assert_int(ft_norm(strncmp("a\0Df", "asdf", 3)), ==, ft_norm(ft_strncmp("a\0Df", "asdf", 3)));
	munit_assert_int(ft_norm(strncmp("asdf", "asdfgh", 5)), ==, ft_norm(ft_strncmp("asdf", "asdfgh", 5)));
	munit_assert_int(ft_norm(strncmp("asdf", "asdfgh", 3)), ==, ft_norm(ft_strncmp("asdf", "asdfgh", 3)));
	munit_assert_int(ft_norm(strncmp("asdfgh", "asdf", 5)), ==, ft_norm(ft_strncmp("asdfgh", "asdf", 5)));
	munit_assert_int(ft_norm(strncmp("asdfgh", "asdf", 3)), ==, ft_norm(ft_strncmp("asdfgh", "asdf", 3)));
	munit_assert_int(ft_norm(strncmp("asd\0gh", "a\0dfgh", 7)), ==, ft_norm(ft_strncmp("asd\0gh", "a\0dfgh", 7)));
	munit_assert_int(ft_norm(strncmp("asdf\0", "asdf\200", 5)), ==, ft_norm(ft_strncmp("asdf\0", "asdf\200", 5)));
	return (MUNIT_OK);
}

MunitResult	ft_memchr_test(const MunitParameter params[], void *data)
{
	char	*str;

	str = "Hello world! This is a funny string w1th lots of 1nteresti\ng char\0acters.";
	munit_assert_ptr_equal(memchr(str, 'o', 10), ft_memchr(str, 'o', 10));
	munit_assert_ptr_equal(memchr(str, 'y', 10), ft_memchr(str, 'y', 10));
	munit_assert_ptr_equal(memchr(str, '\n', 10), ft_memchr(str, '\n', 10));
	munit_assert_ptr_equal(memchr(str, '\n', 70), ft_memchr(str, '\n', 70));
	munit_assert_ptr_equal(memchr(str, '.', 60), ft_memchr(str, '.', 60));
	munit_assert_ptr_equal(memchr(str, '.', 73), ft_memchr(str, '.', 73));
	munit_assert_ptr_equal(memchr(str, '!', 73), ft_memchr(str, '!', 73));
	munit_assert_ptr_equal(memchr(str, 32, 73), ft_memchr(str, 32, 73));
	munit_assert_ptr_equal(memchr(str, 'H', 0), ft_memchr(str, 'H', 0));
	return (MUNIT_OK);
}

MunitResult	ft_memcmp_test(const MunitParameter params[], void *data)
{
	munit_assert_int(ft_norm(memcmp("asdf", "asdf", 3)), ==, ft_norm(ft_memcmp("asdf", "asdf", 3)));
	munit_assert_int(ft_norm(memcmp("a\0dF", "a\0df", 3)), ==, ft_norm(ft_memcmp("a\0dF", "a\0df", 3)));
	munit_assert_int(ft_norm(memcmp("as\0F", "as\0f", 4)), ==, ft_norm(ft_memcmp("as\0F", "as\0f", 4)));
	munit_assert_int(ft_norm(memcmp("AsdF", "asdf", 0)), ==, ft_norm(ft_memcmp("AsdF", "asdf", 0)));
	munit_assert_int(ft_norm(memcmp("AsdF", "asdf", 1)), ==, ft_norm(ft_memcmp("AsdF", "asdf", 1)));
	munit_assert_int(ft_norm(memcmp("", "", 0)), ==, ft_norm(ft_memcmp("", "", 0)));
	munit_assert_int(ft_norm(memcmp("AsdF", "asdf", 0)), ==, ft_norm(ft_memcmp("AsdF", "asdf", 0)));
	munit_assert_int(ft_norm(memcmp("asd\200", "asd\0", 4)), ==, ft_norm(ft_memcmp("asd\200", "asd\0", 4)));
	munit_assert_int(ft_norm(memcmp("asd\0", "asd\200", 4)), ==, ft_norm(ft_memcmp("asd\0", "asd\200", 4)));
	return (MUNIT_OK);
}

MunitResult	ft_strnstr_test(const MunitParameter params[], void *data)
{
	char *str = "This is a very long string with lots of fun\ny things in it. A a A\0z";

	munit_assert_ptr_equal(NULL, ft_strnstr(str, "is", 0));
	munit_assert_ptr_equal(&str[2], ft_strnstr(str, "is", 10));
	munit_assert_ptr_equal(&str[2], ft_strnstr(str, "is", 900));
	munit_assert_ptr_equal(&str[0], ft_strnstr(str, "\0", 69));
	munit_assert_ptr_equal(&str[0], ft_strnstr(str, "", 69));
	munit_assert_ptr_equal(&str[0], ft_strnstr(str, "This", 69));
	munit_assert_ptr_equal(&str[4], ft_strnstr(str, " ", 67));
	munit_assert_ptr_equal(NULL, ft_strnstr(str, "z", 68));
	munit_assert_ptr_equal(NULL, ft_strnstr(str, "funny", 67));
	munit_assert_ptr_equal(NULL, ft_strnstr(str, "offun", 67));
	munit_assert_ptr_equal(&str[37], ft_strnstr(str, "of fun", 67));
	munit_assert_ptr_equal(&str[43], ft_strnstr(str, "\n", 67));
	munit_assert_ptr_equal(&str[8], ft_strnstr(str, "a", 70));
	munit_assert_ptr_equal(&str[15], ft_strnstr(str, "lo", 70));
	munit_assert_ptr_equal(NULL, ft_strnstr(str, "lotz", 70));
	munit_assert_ptr_equal(NULL, ft_strnstr(str, ".", 30));
	munit_assert_ptr_equal(&str[58], ft_strnstr(str, ".", 70));
	munit_assert_ptr_equal(NULL, ft_strnstr(str, "long string", 20));
	return (MUNIT_OK);
}

MunitResult	ft_calloc_test(const MunitParameter params[], void *data)
{
	char	*str1, *str2;

	str1 = calloc(sizeof(char), 20);
	str2 = ft_calloc(sizeof(char), 20);

	munit_assert_char(str1[5], ==, str2[5]);
	munit_assert_char(str1[8], ==, 0);
	munit_assert_memory_equal(20, str1, str2);
	munit_assert_ptr_equal(
		calloc(999999999, 999999999),
		ft_calloc(999999999, 999999999)
	);
	free(str1);
	free(str2);
	return (MUNIT_OK);
}

MunitResult	ft_isalnum_test(const MunitParameter params[], void *data)
{
	int	i;

	i = 0;
	while (i < 128)
	{
		munit_assert_int((isalnum(i) > 0), ==, (ft_isalnum(i) > 0));
		i++;
	}
	return (MUNIT_OK);
}

MunitResult	ft_isalpha_test(const MunitParameter params[], void *data)
{
	int	i;

	i = 0;
	while (i < 128)
	{
		munit_assert_int((isalpha(i) > 0), ==, (ft_isalpha(i) > 0));
		i++;
	}
	return (MUNIT_OK);
}

MunitResult	ft_isascii_test(const MunitParameter params[], void *data)
{
	int	i;

	i = -1;
	while (i < 180)
	{
		munit_assert_int((isascii(i) > 0), ==, (ft_isascii(i) > 0));
		i++;
	}
	return (MUNIT_OK);
}

MunitResult	ft_isdigit_test(const MunitParameter params[], void *data)
{
	int	i;

	i = 0;
	while (i < 128)
	{
		munit_assert_int((isdigit(i) > 0), ==, (ft_isdigit(i) > 0));
		i++;
	}
	return (MUNIT_OK);
}

MunitResult	ft_isprint_test(const MunitParameter params[], void *data)
{
	int	i;

	i = 0;
	while (i < 128)
	{
		munit_assert_int((isprint(i) > 0), ==, (ft_isprint(i) > 0));
		i++;
	}
	return (MUNIT_OK);
}

MunitResult	ft_tolower_test(const MunitParameter params[], void *data)
{
	int	i;

	i = 0;
	while (i < 128)
	{
		munit_assert_char(tolower(i), ==, ft_tolower(i));
		i++;
	}
	return (MUNIT_OK);
}

MunitResult	ft_toupper_test(const MunitParameter params[], void *data)
{
	int	i;

	i = 0;
	while (i < 128)
	{
		munit_assert_char(toupper(i), ==, ft_toupper(i));
		i++;
	}
	return (MUNIT_OK);
}

MunitTest part1_tests[] = {
{
	"/ft_atoi",
	ft_atoi_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_bzero",
	ft_bzero_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_calloc",
	ft_calloc_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_isalnum",
	ft_isalnum_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_isalpha",
	ft_isalpha_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_isascii",
	ft_isascii_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_isdigit",
	ft_isdigit_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_isprint",
	ft_isprint_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_memchr",
	ft_memchr_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_memcmp",
	ft_memcmp_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_memcpy",
	ft_memcpy_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_memmove",
	ft_memmove_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_memset",
	ft_memset_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_strchr",
	ft_strchr_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_strdup",
	ft_strdup_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_strlcat",
	ft_strlcat_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_strlcpy",
	ft_strlcpy_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_strlen",
	ft_strlen_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_strncmp",
	ft_strncmp_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_strnstr",
	ft_strnstr_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_strrchr",
	ft_strrchr_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_tolower",
	ft_tolower_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_toupper",
	ft_toupper_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL
}
};
#endif

#if (TEST_PART_2 == true)
MunitResult	ft_substr_test(const MunitParameter params[], void *data)
{
	munit_assert_string_equal(ft_substr("asdfghj", 0, 3), "asd");
	munit_assert_string_equal(ft_substr("asdfghj", 0, 20), "asdfghj");
	munit_assert_string_equal(ft_substr("", 0, 3), "");
	munit_assert_string_equal(ft_substr("", 0, 0), "");
	munit_assert_string_equal(ft_substr("asdf", 0, 0), "");
	munit_assert_string_equal(ft_substr("asdf", -5, -3), "");
	munit_assert_string_equal(ft_substr("asdf\0fdsa", 0, 6), "asdf");
	munit_assert_string_equal(ft_substr("a\r \ndfghj", 0, 5), "a\r \nd");
	munit_assert_string_equal(ft_substr("asdfghj qwer", 8, 3), "qwe");
	munit_assert_string_equal(ft_substr("asdfghj qwer", 11, 3), "r");
	munit_assert_string_equal(ft_substr("asdfghj qwer", 6, 12), "j qwer");
	return (MUNIT_OK);
}

MunitResult	ft_itoa_test(const MunitParameter params[], void *data)
{
	munit_assert_string_equal(ft_itoa(1), "1");
	munit_assert_string_equal(ft_itoa(9), "9");
	munit_assert_string_equal(ft_itoa(10), "10");
	munit_assert_string_equal(ft_itoa(11), "11");
	munit_assert_string_equal(ft_itoa(2147483647), "2147483647");
	munit_assert_string_equal(ft_itoa(5000), "5000");
	munit_assert_string_equal(ft_itoa(-44), "-44");
	munit_assert_string_equal(ft_itoa(-6000), "-6000");
	munit_assert_string_equal(ft_itoa(-789000), "-789000");
	munit_assert_string_equal(ft_itoa(-2147483648), "-2147483648");
	munit_assert_string_equal(ft_itoa(0), "0");
	munit_assert_string_equal(ft_itoa(-1), "-1");
	return (MUNIT_OK);
}

MunitResult	ft_strjoin_test(const MunitParameter params[], void *data)
{
	munit_assert_string_equal(ft_strjoin("asdf", "fghj"), "asdffghj");
	munit_assert_string_equal(ft_strjoin("a", "fghj"), "afghj");
	munit_assert_string_equal(ft_strjoin("asdf", "j"), "asdfj");
	munit_assert_string_equal(ft_strjoin("asdf", ""), "asdf");
	munit_assert_string_equal(ft_strjoin("", "fghj"), "fghj");
	munit_assert_string_equal(ft_strjoin("asdf", "fghj"), "asdffghj");
	munit_assert_string_equal(ft_strjoin("", ""), "");
	return (MUNIT_OK);
}

MunitResult	ft_strtrim_test(const MunitParameter params[], void *data)
{
	munit_assert_string_equal(ft_strtrim("   asdf     ", " "), "asdf");
	munit_assert_string_equal(ft_strtrim("asdf    ", " "), "asdf");
	munit_assert_string_equal(ft_strtrim("    asdf", " "), "asdf");
	munit_assert_string_equal(ft_strtrim("asdf", " "), "asdf");
	munit_assert_string_equal(ft_strtrim("asdf", ""), "asdf");
	munit_assert_string_equal(ft_strtrim("", ""), "");
	munit_assert_string_equal(ft_strtrim("", "asdf"), "");
	munit_assert_string_equal(ft_strtrim("QWEWQasdfEEEEEWWWWQEEEW", "QWE"), "asdf");
	munit_assert_string_equal(ft_strtrim("QWEWQaEEEEEWWWWQEEEW", "QWERT"), "a");
	munit_assert_string_equal(ft_strtrim("EEEEasfdEEEsdfdsEdfEE", "E"), "asfdEEEsdfdsEdf");
	munit_assert_string_equal(ft_strtrim("aaaaaaaa", "a"), "");
	return (MUNIT_OK);
}

MunitResult	ft_split_test(const MunitParameter params[], void *data)
{
	char	**array = ft_split("   sdfsdf gerg 12345   erter", ' ');

	munit_assert_string_equal(array[0], "sdfsdf");
	munit_assert_string_equal(array[1], "gerg");
	munit_assert_string_equal(array[2], "12345");
	munit_assert_string_equal(array[3], "erter");
	munit_assert_ptr_null(array[4]);
	free(array[0]);
	free(array[1]);
	free(array[2]);
	free(array[3]);
	free(array);

	array = ft_split("", ' ');
	munit_assert_ptr_null(array[0]);
	free(array);

	array = ft_split("asdf qwerty", '0');
	munit_assert_string_equal(array[0], "asdf qwerty");
	munit_assert_ptr_null(array[1]);
	free(array[1]);
	free(array);

	array = ft_split("44444444", '4');
	munit_assert_ptr_null(array[0]);
	free(array);
	return (MUNIT_OK);
}

char	ft_toupper_map(unsigned int i, char c)
{
	(void) i;
	return (ft_toupper(c));
}

MunitResult	ft_strmapi_test(const MunitParameter params[], void *data)
{
	char *str = ft_strdup("Hello world! This is a str1ng that can bE UPCased.");
	char *str2 = ft_strmapi(str, &ft_toupper_map);

	munit_assert_string_equal(
		str2,
		"HELLO WORLD! THIS IS A STR1NG THAT CAN BE UPCASED."
	);

	char *str3 = calloc(1, 1);
	char *str4 = ft_strmapi(str, &ft_toupper_map);
	munit_assert_string_equal(str4, "HELLO WORLD! THIS IS A STR1NG THAT CAN BE UPCASED.");
	free(str);
	free(str2);
	free(str3);
	free(str4);
	return (MUNIT_OK);
}

void	ft_toupper_iter(unsigned int i, char *c)
{
	(void) i;
	*c = ft_toupper(*c);
}

MunitResult	ft_striteri_test(const MunitParameter params[], void *data)
{
	char *str = ft_strdup("Hello world! This is a str1ng that can bE UPCased.");

	ft_striteri(str, &ft_toupper_iter);
	munit_assert_string_equal(
		str,
		"HELLO WORLD! THIS IS A STR1NG THAT CAN BE UPCASED."
	);
	free(str);
	return (MUNIT_OK);
}

MunitResult	ft_putchar_fd_test(const MunitParameter params[], void *data)
{
	return (MUNIT_SKIP);
}

MunitResult	ft_putstr_fd_test(const MunitParameter params[], void *data)
{
	return (MUNIT_SKIP);
}

MunitResult	ft_putendl_fd_test(const MunitParameter params[], void *data)
{
	return (MUNIT_SKIP);
}

MunitResult	ft_putnbr_fd_test(const MunitParameter params[], void *data)
{
	return (MUNIT_SKIP);
}

MunitTest part2_tests[] = {
{
	"/ft_itoa",
	ft_itoa_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_putchar_fd",
	ft_putchar_fd_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_putendl_fd",
	ft_putendl_fd_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_putnbr_fd",
	ft_putnbr_fd_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_putstr_fd",
	ft_putstr_fd_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_split",
	ft_split_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_striteri",
	ft_striteri_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_strjoin",
	ft_strjoin_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_strmapi",
	ft_strmapi_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_strtrim",
	ft_strtrim_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	"/ft_substr",
	ft_substr_test,
	NULL,
	NULL,
	MUNIT_TEST_OPTION_NONE,
	NULL
},
{
	NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL
}
};
#endif

#if (TEST_BONUS == true)
MunitTest bonus_tests[] = {
// Sometime soon?
};
#endif

static MunitSuite test_suites[] = {
	#if (TEST_PART_1 == true)
	{ "/part-1", part1_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE },
	#endif
	#if (TEST_PART_2 == true)
	{ "/part-2", part2_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE },
	#endif
	#if (TEST_BONUS == true)
	{ "/bonus", bonus_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE },
	#endif
	{ NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE }
};

static const MunitSuite suite = {
	"/libft",
	NULL,
	test_suites,
	1,
	MUNIT_SUITE_OPTION_NONE
};

int	main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	return (munit_suite_main(&suite, NULL, argc, argv));
}
