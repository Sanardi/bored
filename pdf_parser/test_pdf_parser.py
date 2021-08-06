import unittest
from phonebook import PhoneBook
import wordmatch

class PhonebookTest(unittest.TestCase):
    """Test Class for testing imagiary phonebook script"""
    
    
    def setUp(self) -> None:
        self.phonebook = PhoneBook()

    def tearDown(self) -> None:
        pass

    def test_lookup_by_name(self):
        self.phonebook.add("Bob", "12345")
        number = self.phonebook.lookup("Bob")
        self.assertEqual("12345", number)

    def test_missing_name(self):
        with self.assertRaises(KeyError):
            self.phonebook.lookup("Angie")

    #@unittest.skip("WIP")
    def test_empty_phonebook_is_consistent(self):
        self.assertTrue(self.phonebook.is_consistent())
        
    def test_is_consistent(self):
        self.phonebook.add("Bob", "12345")
        self.phonebook.add("Anna", "012345")
        self.assertTrue(self.phonebook.is_consistent())

    def test_inconsistent_with_duplicate_entries(self):
        self.phonebook.add("Bob", "12345")
        self.phonebook.add("Sue", "12345")
        self.assertFalse(self.phonebook.is_consistent())

    def test_inconsistent_with_different_prefixes(self):
        self.phonebook.add("Bob", "12345")
        self.phonebook.add("Sue", "123")
        self.assertFalse(self.phonebook.is_consistent())

    def test_phonebook_adds_names_and_numbers(self):
        self.phonebook.add("Richard", "09158")
        self.assertIn("Richard", self.phonebook.get_names())
        self.assertIn("09158", self.phonebook.get_numbers())


class WordMatchTest(unittest.TestCase):
    """Test Class for testing wordmatch funtion"""

    def setUp(self) -> None:
        self.match = wordmatch.match

    def tearDown(self) -> None:
        pass

    def test_match_same_length(self):
        word = "obb"
        allowed_letters = "bob"
        self.assertTrue(self.match(word, allowed_letters))

    def test_match_different_length(self):
        word = "obb"
        allowed_letters = "bobby"
        self.assertTrue(self.match(word, allowed_letters))

    def test_no_match_different_length(self):
        word = "xyz"
        allowed_letters = "bobby"
        self.assertFalse(self.match(word, allowed_letters))

    def test_no_match_same_length(self):
        word = "xyzdW"
        allowed_letters = "bobby"
        self.assertFalse(self.match(word, allowed_letters))
