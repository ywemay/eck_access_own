# ECK access own

ECK Access Own appends capability to specify owner access to view, edit and delete for the entities created by Entity Construction Kit.

# Usage example

This example describes the way that was used to create the results represented in attached screen-shoots.

Consider a task list where users having different roles can see each other's tasks. However, they can edit and delete their own tasks only.

For the purpose of such demo - using ECK (Entity Construction Kit) user interface create a new entity type called Note with a bundle named Task. Create two (or more) user roles: manager, salesperson... Grant permissions for manager and sale person groups to view, edit and delete their own Task entities.

Create a view to pull all Task entities in a table. Append Author relationship to be able to view record author names and roles. In the view append the fields: Title, User: Name, User: Roles, Link Own, Edit link Own, Delete link Own. One can merge the links into one column in views.

Use different user accounts with different user permissions to create Task entities.

Depending on logged in user the links in the view shall relate to user's roles access configuration.

# Related modules
ECK Permissions - module that appends Permissions tab to ECK interface to facilitate focusing on current edited entity permissions.
