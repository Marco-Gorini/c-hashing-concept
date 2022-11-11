# c-hashing-concept

//EXPLANATION

//  In cybersecurity, there are three fundamentals concepts regarding the data, that we can also abbreviate as CIA (Confidentiality, Integrity, Availability). A hash function is used to ensure the integrity: what could happen if a cyber-criminal, for example using a MitM technique (Man in the middle), change the message that a friend want to send to you? And, thinking about something worse, what could happen if the USA President want to send a message to the Italian one, that tells "Hey, how are you?", and a cybercriminal change it into "I want to declare war to Italy"? Obviously this is an exaggerated example, but the thing is that the data needs to be sent and received in their correct way. To make it possible, an important tool is to hash the messages, so to convert them into other strings with an algorithm (easy to implement, difficult to reverse). The converted string has to be possibly unique for every different string ( we will understand why at the end). Let's view an example:
//    - I want to send a "Hello" message to my friend
//    - I convert it into a string, like this: "htrg"
//    - My friend receive the message "Hello", and to be sure that the message is correct,      use the same algorithm I used to convert the string, and the converted string is        "htrg". In this case he is sure that I effectively sent the message "Hello"
//    - In another case, my friend could receive the message "hello, how are you". He           converts the string with my same algorithm, and the converted string is "hagtrer".      It is different from mine! This means that someone changed the content of the           message

//  Here is an example of a easy hash function that converts a random generated string to a hashed one, using a hash table. It is easy to revert, but it is just to make understand you the concept.I will try the algorithm 50 times: all the strings need to be equals!
