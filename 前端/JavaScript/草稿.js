var json = {
        "employees": [
            {
                "firstName": "John",
                "lastName": "Doe"
                }, 
            {
                "firstName": "Anna",
                "lastName": "Smith"
                },
            {
                "firstName": "Peter",
                "lastName": "Jones"
                }
    ]
};
json=json.employees; 
​for(var i = 0; i < json.length; i++)
{
    alert(json[i].firstName + " " + json[i].lastName);
} 