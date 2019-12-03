This module is useful when you need to recreate a user. 
The module main feature is to transfer user content from one user to another.

The workflow:
1) Log in as administator.
2) Open 'Edit user' page of the user you need to recreate on admin dashboard. Url is like: /user/1594/edit

3) Click to cancel the account (Url is like: /user/1594/cancel) and select 
   'Delete the account and make its content belong to the Anonymous user.'
   When processed the module creates a file on folder /user-recreate. 
   The file name is like 1594.sql There are a node and media content 
   IDs of deleted user in the file.

4) Create a new user (Let's assume that the new user ID is 1595), and run "drush ruc 1594 1595". 
   This command assigns the content of user 1594 to user 1595 using the file created on step 3).
