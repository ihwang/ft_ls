/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:54:15 by ihwang            #+#    #+#             */
/*   Updated: 2019/10/29 18:26:54 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	lstdel_example(void *lst, size_t size)
{
	free(lst);
	lst = NULL;
	size = 0;
}

void	lsddel_example(void *lst, size_t size)
{
	free(lst);
	lst = NULL;
	size = 0;
}

char    strmapi_example(unsigned int i, char c)
{
    c += i;
    return (c);
}

char	strmap_example(char c)
{
	c++;
	return (c);
}

void	striteri_example(unsigned int i, char *str)
{
	str[i] = '\0';
}

t_list	*lst_mapping(t_list *elem)
{
	*(int*)elem->content = *(int*)elem->content + 1;
	return (elem);
}

void	lstdelone_example(void *lst, size_t size)
{
	free(lst);
	lst = NULL;
	size = 0;
}

void	example1(void *lst, size_t size)
{
	free(lst);
	lst = NULL;
	size = 0;
}

void	striter_example(char *str)
{
	*str = '\0';
}

int main(void)
{
	printf("\ntest_atoi\n");
	char *str1 = "-2147483648";
    char *str2 = "2147483647";
    char *str3 = "2352352";
    char *str4 = "0";
    char *str5 = "-1";
    char *str6 = "      0";	
    printf("-2147483648 and %d\n", ft_atoi(str1));
    printf("2147483647 and %d\n", ft_atoi(str2));
    printf("2352352 and %d\n", ft_atoi(str3));
    printf("0 and %d\n", ft_atoi(str4));
    printf("-1 and %d\n", ft_atoi(str5));
    printf("0 and %d\n", ft_atoi(str6));


	printf("\ntest_bzero\n");
 	char str7[5] = "abcd";
    printf("abcd and %s\n", str7);
    ft_bzero(str7, 4);
    printf("\"\" and \"%s\"\n", str7);


	printf("\ntest_is\n");
	printf("isalnum\n1 and %d\n0 and %d\n", ft_isalnum('z'), ft_isalnum(' '));
	printf("isalpha\n1 and %d\n0 and %d\n", ft_isalpha('z'), ft_isalpha('4'));
	printf("isascii\n1 and %d\n0 and %d\n", ft_isascii('a'), ft_isascii(301));
	printf("isdigit\n1 and %d\n0 and %d\n", ft_isdigit('0'), ft_isdigit('a'));
	printf("isprint\n1 and %d\n0 and %d\n", ft_isprint(' '), ft_isprint(12));


	printf("\ntest_itoa\n");
	int nb1 = -199;
    int nb2 = 199;
    int nb3 = 0;
    int nb4 = 2147483647;
    int nb5 = -2147483648;
    char *str8;
    char *str9;
    char *str10;
    char *str11;
    char *str12;
    str8 = ft_itoa(nb1);
    str9 = ft_itoa(nb2);
    str10 = ft_itoa(nb3);
    str11 = ft_itoa(nb4);
    str12 = ft_itoa(nb5);
    printf("-199 and %s\n", str8);
    printf("199 and %s\n", str9);
    printf("0 and %s\n", str10);
    printf("2147483647 and %s\n", str11);
    printf("-2147483648 and %s\n", str12);


	printf("\ntest_lstdel\n");
	t_list **lstdel_alst;
	int lstdel_nb = 42;
	int *lstdel_content = &lstdel_nb;
	lstdel_alst = (t_list**)malloc(sizeof(t_list*));
	*lstdel_alst = ft_lstnew(lstdel_content, 4);
	printf("42 and %d\n", *(int*)lstdel_alst[0]->content);
	ft_lstdel(lstdel_alst, example1);
	printf("0x0 and %p\n", lstdel_alst[0]);


	printf("\ntest_lstdelone\n");
	t_list **lstdelone_alst;
	int lstdelone_nb = 42;
	int *lstdelone_content = &lstdelone_nb;
	lstdelone_alst = (t_list**)malloc(sizeof(t_list*) * 2);
	lstdelone_alst[0] = ft_lstnew(lstdelone_content, 4);
	printf("42 and %d\n", *(int*)lstdelone_alst[0]->content);
	ft_lstdelone(lstdelone_alst, lstdelone_example);
	printf("0x0 and %p\n", lstdelone_alst[0]);
	

	printf("\ntest_lstmap\n");
	t_list *lstmap_lst1;
    t_list *lstmap_lst2;
    int lstmap_nb1 = 42;
    int lstmap_nb2 = 24;
    int *lstmap_content1 = &lstmap_nb1;
    int *lstmap_content2 = &lstmap_nb2;
    t_list *lstmap_mapped;
    lstmap_lst1 = ft_lstnew(lstmap_content1, 4);
    lstmap_lst2 = ft_lstnew(lstmap_content2, 4);
    lstmap_lst1->next = lstmap_lst2;
    lstmap_mapped = ft_lstmap(lstmap_lst1, lst_mapping);
	printf("original address : %p\n", lstmap_lst1);
	printf("mapped address : %p\n", lstmap_mapped);
    printf("43 and %d\n", *(int*)lstmap_mapped->content);
    lstmap_mapped = lstmap_mapped->next;
    printf("25 and %d\n", *(int*)lstmap_mapped->content);


	printf("\ntest_lstnew\n");
	t_list *lstnew_node;
    int lstnew_nb = 42;
    int *lstnew_pt = &lstnew_nb;
    lstnew_node = ft_lstnew(lstnew_pt, 4);
    printf("42 and %d\n", *(int*)(lstnew_node->content));
	*(int*)lstnew_node->content = 10;
	printf("10 and %d\n", *(int*)(lstnew_node->content));
    printf("4 and %zu\n", lstnew_node->content_size);
    printf("0x0 and %p\n", lstnew_node->next);
	

	printf("\ntest_memalloc\n");
	int *memalloc_tab1;
    int memalloc_i = 0;
    memalloc_tab1 = (int*)ft_memalloc(sizeof(int) * 5);
	printf("0\n0\n0\n0\n0\nand\n");
    while (memalloc_i < 5)
        printf("%d\n", memalloc_tab1[memalloc_i++]);


	printf("\ntest_memccpy\n");
	char memccpy_str1[] = "abcd";
	char memccpy_str2[] = "wxyz";
    printf("The expected is : 'NULL' and return is : %s\n", ft_memccpy(memccpy_str1, memccpy_str2, 'z', 2));
    printf("The expected is : 'wxcd' and return is : %s\n", memccpy_str1);
    printf("d and %c\n", *(unsigned char*)ft_memccpy(memccpy_str1, memccpy_str2, 'y', 3));
    printf("wxyd and %s\n", memccpy_str1);


	printf("\ntest_memchr\n");
	char memchr_str[] = "abcdefg";
	printf("d and %c\n", *(unsigned char*)ft_memchr(memchr_str, 'd', 6));
    printf("abcdefg and %s\n", memchr_str);


	printf("\ntest_memcmp\n");
	char memcmp_str1[] = "";
    char memcmp_str2[] = "";
    char memcmp_str3[] = "aba";
    char memcmp_str4[] = "abc";
    printf("0 and %d\n", ft_memcmp(memcmp_str1, memcmp_str2, 4));
    printf("-2 and %d\n", ft_memcmp(memcmp_str3, memcmp_str4, 3));


	printf("\ntest_memcpy\n");
	char memcpy_str1[] = "abcd";
    char memcpy_str2[] = "zzzz";
    printf("aaa and %s\n", ft_memcpy(memcpy_str1 + 1, memcpy_str1, 3));
    //str + 1
    printf("aaaa and %s\n", memcpy_str1);
    //str1
    printf("zzzz and %s\n", ft_memcpy(memcpy_str1, memcpy_str2, 4));
    //str1
	

	printf("\ntest_memdel\n");
	void **memdel_pt1;
	void *memdel_pt2;
	memdel_pt1 = (void**)malloc(3);
	printf("Double pointer allocated : %p\n", memdel_pt1);
	memdel_pt1[0] = (void*)malloc(3);
	printf("The sub-pointer is allocated : %p\n", memdel_pt1[0]);
	ft_memdel(memdel_pt1);
	printf("sub is freed : %p\n", memdel_pt1[0]);
	memdel_pt2 = (void*)malloc(3);
	ft_memdel((void**)&memdel_pt2);


	printf("\ntest_memmove\n");
	char memmove_str1[] = "abcd";
	char memmove_str2[] = "zzzz";
	printf("abc and %s\n", ft_memmove(memmove_str1 + 1, memmove_str1, 3));
	//str1 + 1
	printf("aabc and %s\n", memmove_str1);
	//str
	printf("zzzc and %s\n", ft_memmove(memmove_str1, memmove_str2, 3));
	//str1
	

	printf("\ntest_memset\n");
	char memset_str[7];
	printf("aaaaaa and %s\n", ft_memset(memset_str, 'a', 6));
    //str
	

	printf("\ntest_putchar_fd\n");
	char putchar_fd_c = 'a';
	ft_putchar_fd(putchar_fd_c, 1);
	printf(" and a\n");


	printf("\n\ntest_putendl\n");
	char *putendl_str = "abcd";
	ft_putendl(putendl_str);
	printf("and\nabcd\n");


	printf("\ntest_putnbr\n");
	int putnbr_nb1 = 1;
	int putnbr_nb2 = 0;
	int putnbr_nb3 = -1;
	int putnbr_nb4 = 23522;
	int putnbr_nb5 = 214783647;
	int putnbr_nb6 = -214783648;
	ft_putnbr(putnbr_nb1);
	ft_putchar('\n');
	ft_putnbr(putnbr_nb2);
	ft_putchar('\n');
	ft_putnbr(putnbr_nb3);
	ft_putchar('\n');
	ft_putnbr(putnbr_nb4);
	ft_putchar('\n');
	ft_putnbr(putnbr_nb5);
	ft_putchar('\n');
	ft_putnbr(putnbr_nb6);
	ft_putchar('\n');
	printf("and\n1\n0\n-1\n23522\n214783647\n-214783648\n");


	printf("\ntest_putstr\n");
	char *putstr_str = "abcd";
	ft_putstr(putstr_str);
	printf("\n");


	printf("\ntest_strcat\n");
	char strcat_str1[10] = "abcde";
    char strcat_str2[] = "zzzz";
    printf("abcdezzzz and %s\n", ft_strcat(strcat_str1, strcat_str2));
    //str1
    printf("zzzz and %s\n", strcat_str2);


	printf("\ntest_strchr\n");
	char *strchr_str1 = "abcde";
    printf("null and %s\n", ft_strchr(strchr_str1, 'z'));
    printf("cde and %s\n", ft_strchr(strchr_str1, 'c'));
    printf("abcde and %s\n", strchr_str1);


	printf("\ntest_strclr\n");
	char strclr_str[] = "abcd";
	ft_strclr(strclr_str);
	printf("\"\" and \"%s\"\n", strclr_str);


	printf("\ntest_strcmp\n");
	char *strcmp_str1 = "abcd";
    char *strcmp_str2 = "abce";
    char *strcmp_str3 = "aaa";
    printf("-1 and %d\n", ft_strcmp(strcmp_str1, strcmp_str2));
    printf("1 and %d\n", ft_strcmp(strcmp_str1, strcmp_str3));
    printf("0 and %d\n", ft_strcmp(strcmp_str1, strcmp_str1));


	printf("\ntest_strcpy\n");
	char strcpy_str1[] = "abcd";
    char strcpy_str2[5] = "";
    char strcpy_str3[] = "zzzz";
    printf("\"\" and \"%s\"\n", ft_strcpy(strcpy_str1, strcpy_str2));
    //str1
    printf("zzzz and %s\n", ft_strcpy(strcpy_str1, strcpy_str3));
    //str1
	

	printf("\ntest_strdel\n");
	char **strdel_pt1;
	char *strdel_pt2;
	strdel_pt1 = (char**)malloc(3);
	printf("Double pointer allocated : %p\n", strdel_pt1);
	strdel_pt1[0] = (char*)malloc(3);
	printf("sub-pointer is allocated : %p\n", strdel_pt1[0]);
	ft_strdel(strdel_pt1);
	printf("The sub is freed : %p\n", strdel_pt1[0]);
	strdel_pt2 = (char*)malloc(3);
	ft_strdel(&strdel_pt2);


	printf("\ntest_strdup\n");
	char strdup_str1[] = "abcd";
    char strdup_str2[] = "";
    printf("abcd and %s\n", ft_strdup(strdup_str1));
    //str1
    printf("\"\" and \"%s\"\n", ft_strdup(strdup_str2));
    //str2
	

	printf("\ntest_strequ\n");
	char *strequ_str1 = "abcd";
    char *strequ_str2 = "abc";
    printf("0 and %d\n", ft_strequ(strequ_str1, strequ_str2));
    printf("1 and %d\n", ft_strequ(strequ_str1, strequ_str1));


	printf("\ntest_striter\n");
	char *striter_str;
	striter_str = (char*)malloc(5);
	strcpy(striter_str, "abcd");
	ft_striter(striter_str, striter_example);
	printf("\"\" and \"%s\"\n", striter_str);
	free(striter_str);


	printf("\ntest_striteri\n");
	char *striteri_str;
	striteri_str = (char*)malloc(5);
	strcpy(striteri_str, "abcd");
	ft_striteri(striteri_str, striteri_example);
	printf("\"\" abd \"%s\"\n", striteri_str);


	printf("\ntest_strjoin\n");
	char *strjoin_str1;
	char *strjoin_str2;
	strjoin_str1 = (char*)malloc(5);
	strjoin_str2 = (char*)malloc(5);
	strcpy(strjoin_str1, "abcd");
	strcpy(strjoin_str2, "efgh");
	printf("abcdefgh and %s\n", ft_strjoin(strjoin_str1, strjoin_str2));


	printf("\ntest_strlcat\n");
	char strlcat_str1[15] = "abcde";
    char strlcat_str2[] = "zzz";
    printf("8 and %lu\n", ft_strlcat(strlcat_str1, strlcat_str2, 13));
    printf("abcdezzz and %s\n", strlcat_str1);


	printf("\ntest_strlen\n");
	char strlen_str[] = "abcd";
    printf("4 and %zu\n", ft_strlen(strlen_str));
	

	printf("\ntest_strmap\n");
	char *strmap_str1;
	char *strmap_str2;
	strmap_str1 = (char*)malloc(5);
	strcpy(strmap_str1, "abcd");
	strmap_str2 = ft_strmap(strmap_str1, strmap_example);
	printf("bcde and %s\n", strmap_str2);
	free(strmap_str1);


	printf("\ntest_strmapi\n");
	char *strmapi_str1;
    char *strmapi_str2;
    strmapi_str1 = (char*)malloc(sizeof(char) * 4 + 1);
    ft_strcpy(strmapi_str1, "abcd");
    strmapi_str2 = ft_strmapi(strmapi_str1, strmapi_example);
    printf("abcd and %s\n", strmapi_str1);
    printf("aceg and %s\n", strmapi_str2);


	printf("\ntest_strncat\n");
	char strncat_str1[10] = "abcde";
    char strncat_str2[] = "zzzz";
    printf("abcdezz and %s\n", ft_strncat(strncat_str1, strncat_str2, 2));
    //str1
	

	printf("\ntest_strncmp\n");
	char *strncmp_str1 = "abcde";
    char *strncmp_str2 = "abzzz";
    char *strncmp_str3 = "abc";
    printf("0 and %d\n", ft_strncmp(strncmp_str1, strncmp_str2, 2));
    printf("1 and %d\n", ft_strncmp(strncmp_str1, strncmp_str3, 5));
    printf("-1 and %d\n", ft_strncmp(strncmp_str1, strncmp_str2, 5));


	printf("\ntest_strncpy\n");
	char strncpy_str1[] = "abcde";
    char strncpy_str2[] = "zzzz";
    printf("zzcde and %s\n", ft_strncpy(strncpy_str1, strncpy_str2, 2));
    //str1
    printf("zzzz and %s\n", ft_strncpy(strncpy_str1, strncpy_str2, 5));
    //str1
    printf("4 and %lu\n", strlen(strncpy_str1));


	printf("\ntest_strnequ\n");
	char *strnequ_str1 = "abcd";
    char *strnequ_str2 = "abc";
    printf("1 and %d\n", ft_strnequ(strnequ_str1, strnequ_str2, 3));
    printf("0 and %d\n", ft_strnequ(strnequ_str1, strnequ_str2, 4));


	printf("\ntest_strnew\n");
	char *strnew_str;
	strnew_str = ft_strnew(5);
	strcpy(strnew_str, "abcde");
	printf("given size : 5\nsrc : \"abcde\"\ncopied str : %s\n", strnew_str);


	printf("\ntest_strnstr\n");
	char *strnstr_str1 = "Foo Bar Baz";
    char *strnstr_str2 = "o ";
    char *strnstr_str3 = "Bar";
    printf("\"o Bar Baz\" and %s\n", ft_strnstr(strnstr_str1, strnstr_str2, 4));
    printf("(null) and %s\n", ft_strnstr(strnstr_str1, strnstr_str3, 4));
    printf("(null) and %s\n", ft_strnstr(strnstr_str1, strnstr_str3, 6));
    // The needle argument has to be fully contained in the haystack in the given len.
	

	printf("\ntest_strrchr\n");
	char *strrchr_str1 = "abcade";
    printf("null and %s\n", ft_strrchr(strrchr_str1, 'z'));
    printf("ade and %s\n", ft_strrchr(strrchr_str1, 'a'));
    printf("abcade and %s\n", strrchr_str1);


	printf("\ntest_strsplit\n");
	printf("he fe st (null)\nand\n");
	char *strsplit_str1 = "***he*fe***st";
    char **strsplit_strings;
    int strsplit_i = 1;
    strsplit_strings = ft_strsplit(strsplit_str1, '*');
    while (strsplit_i <= 4)
    {
        printf("%d string's address : %p\n", strsplit_i, strsplit_strings[strsplit_i - 1]);
        printf("%d string's value : %s\n\n", strsplit_i, strsplit_strings[strsplit_i - 1]);
        strsplit_i++;
    }


	printf("\ntest_strstr\n");
	char *strstr_str1 = "Foo Bar Baz Foo";
    char *strstr_str2 = "Foo Baz";
    char *strstr_str3 = "Bar Baz";
    printf("NULL and %s\n", ft_strstr(strstr_str1, strstr_str2));
    printf("\"Bar Baz Foo\" and %s\n", ft_strstr(strstr_str1, strstr_str3));


	printf("\ntest_strsub\n");
	char *strsub_str1 = "abcdefg";
    char *strsub_str2;
    strsub_str2 = ft_strsub(strsub_str1, 2, 4);
    printf("cdef and %s\n", strsub_str2);
    printf("???? and %s\n", ft_strsub(strsub_str1, 7, 4));


	printf("\ntest_strtrim\n");
	char strtrim_str1[] = "  \t\t\n\nabcd  \t\t\n\n";
	printf("abcd and %s\n", ft_strtrim(strtrim_str1));


	printf("\ntest_putchar_fd\n");
	ft_putchar_fd('a', 1);


	printf("\n\ntest_putendl\n");
	printf("abcd\nand\n");
	ft_putendl("abcd");


	printf("\ntest_lstnew\n");
	t_list *node1;
	t_list *node2;
	t_list *node3;
	int nb = 42;
	int *pt1 = &nb;
	node1 = ft_lstnew(pt1, sizeof(int));
	*(int*)node1->content = 10;
	printf("10 and %d\n", *(int*)(node1->content));
	printf("4 and %zu\n", node1->content_size);
	printf("0x0 and %p\n", node1->next);
	node2 = ft_lstnew(pt1, sizeof(int));
	printf("42 and %d\n", *(int*)node2->content);
	nb++;
	node3 = ft_lstnew(pt1, sizeof(int));
	printf("43 and %d\n", *(int*)node3->content);


	printf("\ntest_lstadd and lsddelone\n");
	ft_lstadd(&node1, node2);
	ft_lstadd(&node1, node3);
	t_list *node_copy = node3;
	t_list *node_cpy = node3;
	node_copy = node3;
	node_copy = node_copy->next;
	ft_lstdelone(&node_copy, lsddel_example);
	printf("43\n0\n10\nand\n");
	while (node_cpy)
	{
		printf("%d\n", *(int*)node_cpy->content);
		node_cpy = node_cpy->next;
	}


	printf("\ntest_lstdel\n");
	int nbnb = 4; 
	int *p = &nbnb;
	t_list *node = ft_lstnew(p, nbnb);
	ft_lstdel(&node, lstdel_example);
	printf("0x0 and %p\n", node);
	//printf("%p\n", node3);



	return (0);
}
