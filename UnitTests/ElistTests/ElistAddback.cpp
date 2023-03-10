#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(ElistAddback, ValidNode)
{
	union u_element	u;
	t_elist	first = {sphere, u, NULL};
	t_elist	second = {camera, u, NULL};
	t_elist	third = {light, u, NULL};
	t_elist	*head;

	head = &first;
	elist_addback(&head, &second);
	elist_addback(&head, &third);
	EXPECT_EQ(head->type, sphere);
	EXPECT_EQ(head->next->type, camera);
	EXPECT_EQ(head->next->next->type, light);
}

TEST(ElistAddback, InvalidNode)
{
	union u_element	u;
	t_elist	first = {sphere, u, NULL};
	t_elist	*head;

	head = &first;
	elist_addback(&head, NULL);
	EXPECT_EQ(head->next, nullptr);
}

TEST(ElistAddback, EmptyList)
{
	union u_element	u;
	t_elist	first = {sphere, u, NULL};
	t_elist	*head;

	head = NULL;
	elist_addback(&head, &first);
	EXPECT_EQ(head->type, sphere);
}
