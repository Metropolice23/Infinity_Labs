import unittest
from summary import *


class TestPoint(unittest.TestCase):

    def test_return_file_name(self):
        """"""
        path = '/home/omri/Documents/git_repos/omri-shur/file_ws/func.c'
        self.assertTrue(return_file_name(path) == 'func.c')

    def test_capital_letters_file(self):
        """"""
        path = '/home/omri/Desktop/text.txt'
        capital_letters_file(path)
        with open(path, 'r') as file:
            lines = file.readlines()
        for i in lines:
            self.assertTrue(i.isupper())

    def test_check_if_prime(self):
        """"""
        self.assertTrue(check_if_prime(17))
        self.assertFalse(check_if_prime(49))
        self.assertTrue(check_if_prime(31))

    def test_lambda1(self):
        """"""
        func = lambda1()
        self.assertTrue(func(36) == 6)
        self.assertTrue(func(81) == 9)

    def test_lambda2(self):
        """"""
        func = lambda2()
        self.assertTrue(func(12, 7) == 19)
        self.assertTrue(func(54, 102) == 156)

    def test_dir_list_no_dunder(self):
        """"""
        ls = dir_list_no_dunder(dir(str))
        for i in ls:
            self.assertFalse('__' in i)
        self.assertTrue('format' in ls)

    def test_increment_list(self):
        lis = [29, 39, 29, 19]
        increment_list(lis)
        self.assertTrue(lis[0] == 30)
        self.assertTrue(lis[1] == 40)
        self.assertTrue(lis[2] == 30)
        self.assertTrue(lis[3] == 20)

    def test_remove_not_str_from_list(self):
        lis = [12, 'omri', 34, '56', 55, 'olga']
        nlist = remove_not_str_from_list(lis)
        self.assertTrue(55 not in nlist)
        self.assertTrue('56' in nlist)
        self.assertTrue('omri' in nlist)
        self.assertFalse(12 in nlist)
        self.assertFalse('olga' not in nlist)

    def test_enum_print(self):
        print("********--test_enum_print--********")
        ls = ['zero', 'one', 'two', 'three', 'four']
        enum_print(ls)

    def test_dict_print(self):
        print("********--test_dict_print--********")
        dic = {1: 'uno', 2: 'dos', 3: 'dos', 4: 'tres'}
        dict_print(dic)

    def test_list_to_dict(self):
        ls = ['omri', 'achia', 'asya', 'olga']
        dic = list_to_dict(ls)
        self.assertTrue(dic[0] == 'omri')
        self.assertTrue(dic[1] == 'achia')
        self.assertTrue(dic[2] == 'asya')
        self.assertTrue(dic[3] == 'olga')


    def test_DefaultDict(self):
        defdic = DefaultDict(0)
        defdic1 = DefaultDict(22)
        defdic1.set_item('r', 55)
        defdic.set_item(1, 'first')
        defdic.set_item('a', 'aaa')
        defdic.set_item('b', 'bbb')
        defdic.set_item('c', 40)
        defdic.set_item('d', 'ddd')
        self.assertTrue(defdic.get_item('a') == 'aaa')
        self.assertTrue(defdic.get_item(1) == 'first')
        self.assertTrue(defdic.get_item('c') == 40)
        defdic.set_item('c', 'moshe')
        self.assertTrue(defdic.get_item('c') == 'moshe')
        self.assertFalse(defdic.get_item('c') == 40)
        self.assertFalse(defdic.get_item('d') == 'bbb')
        self.assertTrue(defdic.get_item('achia') == 0)
        self.assertTrue(defdic1.get_item('olga') == 22)


















if __name__ == "__main__":
    unittest.main()
