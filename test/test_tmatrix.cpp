#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(m1);

	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	int n = 5;
	TDynamicMatrix<int> m1(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m1[i][j] = 3;
		}
	}
	TDynamicMatrix<int> m2(m1);
	m2[0][0] = 5;

	EXPECT_EQ(m1[0][0], 3);
	EXPECT_EQ(m2[0][0], 5);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(10);

	EXPECT_EQ(10, m.get_size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(5);
	m[1][1] = 3;

	EXPECT_EQ(m[1][1], 3);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(-1, -1) = 1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(15, 0) = 1);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	ASSERT_NO_THROW(m1 = m2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(5);
	m1 = m2;
	EXPECT_EQ(m1.get_size(), 5);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(5);
	
	ASSERT_NO_THROW(m1 = m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);

	m1[1][1] = 1;
	m2[1][1] = 1;

	EXPECT_TRUE(m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(5);

	m[1][1] = 1;

	EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(10);

	EXPECT_FALSE(m1 == m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);

	ASSERT_NO_THROW(m1 + m2);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(10);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);

	ASSERT_NO_THROW(m1 - m2);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(10);

	ASSERT_ANY_THROW(m1 - m2);
}
//
TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);

	ASSERT_NO_THROW(m1 * m2);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(10);

	ASSERT_ANY_THROW(m1 * m2);
}

TEST(TDynamicMatrix, can_correctly_add_matrices_with_equal_size)
{
	int n = 2;
	TDynamicMatrix<int> m1(n);
	TDynamicMatrix<int> m2(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m1[i][j] = 1;
			m2[i][j] = 2;
		}
	}
	TDynamicMatrix<int> res(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = 3;
		}
	}

	EXPECT_EQ(m1 + m2, res);
}

TEST(TDynamicMatrix, can_correctly_subtract_matrices_with_equal_size)
{
	int n = 2;
	TDynamicMatrix<int> m1(n);
	TDynamicMatrix<int> m2(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m1[i][j] = 1;
			m2[i][j] = 2;
		}
	}
	TDynamicMatrix<int> res(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = -1;
		}
	}

	EXPECT_EQ(m1 - m2, res);
}

TEST(TDynamicMatrix, can_correctly_multiply_matrices_with_equal_size)
{
	int n = 2;
	TDynamicMatrix<int> m1(n);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 2;
	m1[1][1] = 1;

	TDynamicMatrix<int> m2(n);
	m2[0][0] = 3;
	m2[0][1] = 2;
	m2[1][0] = 1;
	m2[1][1] = 1;

	TDynamicMatrix<int> res(n);
	res[0][0] = 5;
	res[0][1] = 4;
	res[1][0] = 7;
	res[1][1] = 5;

	EXPECT_EQ(m1 * m2, res);
}
