/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:10:04 by seojin            #+#    #+#             */
/*   Updated: 2022/07/18 18:41:03 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	free_fct(void *data)
{
	free(data);
}

void	ft_tolower(void *data)
{
	printf("Function is Applied: %s\n", data);
}

void	ft_print_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", list -> data);
		list = list -> next;
	}
}

int main()
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list	*head;

	void	(*free_fct)(void *) = free_fct;
	void	(*ft_tolowe)(void *) = ft_tolower;

	char	*str1 = "THIS IS FIRST ELEM";
	char	*str2 = "THIS IS SECOND ELEM";
	char	*str3 = "THIS IS THIRD ELEM";
	char	*str4 = "THIS IS LAST ELEM";
	char	*data_ref = "THIS IS THIRD ELEM";
	char	**strs = (char **)malloc(5 * sizeof(char *));
	strs[0] = str1;
	strs[1] = str2;
	strs[2] = str3;
	strs[3] = str4;
	strs[4] = 0;

	elem1 = ft_create_elem(str1);
	elem2 = ft_create_elem(str2);
	elem3 = ft_create_elem(str3);
	elem4 = ft_create_elem(str4);
	/*
	printf("----ex00 : ft_create_elem TEST\n----");
	printf("%s\n", elem1 -> data);
	printf("%s\n", elem2 -> data);
	printf("%s\n", elem3 -> data);
	printf("%s\n", elem4 -> data);

	printf("\n\n");

	free(elem1);
	free(elem2);
	free(elem3);
	free(elem4);
	elem1 = NULL;
	


	printf("----ex01 : ft_list_push_front TEST----\n");
	ft_list_push_front(&elem1, str4);
	ft_list_push_front(&elem1, str3);
	ft_list_push_front(&elem1, str2);
	ft_list_push_front(&elem1, str1);
	ft_print_list(elem1);
	printf("\n\n");



	printf("----ex02 : ft_list_size TEST----\n");
	printf("The size of LIST = %d\n", ft_list_size(elem1));
	printf("\n\n");



	printf("----ex03 : ft_list_last TEST\n----");
	printf("%s\n", ft_list_last(elem1) -> data);
	printf("\n\n");



	ft_list_clear(elem1, free_fct);
	
	elem1 = NULL;



	printf("----ex04 : ft_list_push_back TEST----\n");
	ft_list_push_back(&elem1, str1);
	ft_list_push_back(&elem1, str2);
	ft_list_push_back(&elem1, str3);
	ft_list_push_back(&elem1, str4);
	ft_print_list(elem1);
	printf("\n\n");



	ft_list_clear(elem1, free_fct);
	
	elem1 = NULL;



	printf("----ex05 : ft_list_push_strs TEST----\n");
	
	elem1 = ft_list_push_strs(4, strs);
	ft_print_list(elem1);
	printf("\n\n");



	free(strs);
	ft_list_clear(elem1, free_fct);
	elem1 = NULL;


	printf("----ex06 ft_list_clear TEST----\n");
	printf("\n\n");



	printf("----ex07 ft_list_at TEST----\n");
	ft_list_push_back(&elem1, str1);
	ft_list_push_back(&elem1, str2);
	ft_list_push_back(&elem1, str3);
	ft_list_push_back(&elem1, str4);
	printf("second(index 1) data :%s\n", (ft_list_at(elem1, 1)) -> data);
	printf("\n\n");



	printf("----ex08 ft_list_reverse TEST----\n");
	ft_list_reverse(&elem1);
	ft_print_list(elem1);
	printf("\n\n");



	ft_list_clear(elem1, free_fct);
	elem1 = NULL;



	printf("----ex09 ft_list_foreach TEST----\n");
	ft_list_push_back(&elem1, str1);
	ft_list_push_back(&elem1, str2);
	ft_list_push_back(&elem1, str3);
	ft_list_push_back(&elem1, str4);
	ft_list_foreach(elem1, ft_tolowe);
	printf("\n\n");



	ft_list_clear(elem1, free_fct);
	elem1 = NULL;



	printf("----ex10 ft_list_foreach_if TEST----\n");
	ft_list_push_back(&elem1, str1);
	ft_list_push_back(&elem1, str2);
	ft_list_push_back(&elem1, str3);
	ft_list_push_back(&elem1, str4);
	ft_list_foreach_if(elem1, ft_tolower, data_ref, strcmp);
	printf("\n\n");



	printf("----ex11 ft_list_find TEST----\n");
	ft_print_list(ft_list_find(elem1, data_ref, strcmp));
	printf("\n\n");

*/
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	printf("----ex12 ft_list_remove_if TEST----\n");
	ft_list_remove_if(&elem1, data_ref, strcmp, free_fct);
	ft_print_list(elem1);
	printf("\n\n");



	ft_list_clear(elem1, free_fct);
/*	free(elem1 -> next);
	free(elem2 -> next);
	free(elem3 -> next);*/

/*

	printf("----ex13 ft_list_merge TEST----\n");
	char	*b1 = "MERGED DATA";
	t_list	*list2 = ft_create_elem(b1);

	ft_list_push_back(&elem1, str1);
	ft_list_push_back(&elem1, str2);
	ft_list_push_back(&elem1, str3);
	ft_list_push_back(&elem1, str4);
	ft_list_merge(&elem1, list2);
	ft_print_list(elem1);
	printf("\n\n");
	


	ft_list_clear(elem1, free_fct);
	elem1 = NULL;
	list2 = NULL;



	printf("----ex14 ft_list_sort TEST----\n");
	char	*s1 = "apple";
	char	*s2 = "application";
	char	*s3 = "banana";
	char	*s4 = "42seolu";
	char	*s5 = "ananymous";
	char	*s6 = "design";
	ft_list_push_back(&elem1, s1);
	ft_list_push_back(&elem1, s2);
	ft_list_push_back(&elem1, s3);
	ft_list_push_back(&elem1, s4);
	ft_list_push_back(&elem1, s5);
	ft_list_push_back(&elem1, s6);
	ft_list_sort(&elem1, strcmp);
	ft_print_list(elem1);
	printf("\n\n");



	printf("----ex15 ft_list_reverse_fun TEST----\n");
	ft_list_reverse_fun(elem1);
	ft_print_list(elem1);
	printf("\n\n");



	ft_list_reverse_fun(elem1);



	printf("----ex16 ft_sorted_list_insert TEST----\n");
	char	*c1 = "cat";
	ft_sorted_list_insert(&elem1, c1, strcmp);
	ft_print_list(elem1);
	printf("\n\n");



	printf("----ex17 ft_sorted_list_merge TEST----\n");
	char	*d1 = "aaaaaaaaaaaa";
	char	*d2 = "bbbbbbbbbbbbb";
	char	*d3 = "cocacola";
	char	*d4 = "mcdonalds";
	char	*d5 = "burgerKING";
	char	*d6 = "seOjin";
	char	*d7 = "apPle";
	ft_list_push_back(&list2, d1);
	ft_list_push_back(&list2, d2);
	ft_list_push_back(&list2, d3);
	ft_list_push_back(&list2, d4);
	ft_list_push_back(&list2, d5);
	ft_list_push_back(&list2, d6);
	ft_list_push_back(&list2, d7);
	ft_list_sort(&list2, strcmp);
	ft_sorted_list_merge(&elem1, list2, strcmp);
	ft_print_list(elem1);
	ft_list_clear(elem1, free_fct);
*/
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	
	return 0;
}
