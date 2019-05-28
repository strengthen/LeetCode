__________________________________________________________________________________________________
SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person LEFT JOIN Address ON Person.PersonId = Address.PersonId;
__________________________________________________________________________________________________
SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person LEFT JOIN Address USING(PersonId);
__________________________________________________________________________________________________
SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person NATURAL LEFT JOIN Address;