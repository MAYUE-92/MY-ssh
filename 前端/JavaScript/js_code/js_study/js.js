function text(){
    var json = {
        "employees": [
            {"firstname": "john", "lastname": "Done"},
            {"firstname": "anna", "lastname": "smith"},
            {"firstname": "peter", "lastname": "jones"}
        ]
    }


json = eval(json.employees);//
for(var i=0;i<json.length;i++){
    alert(json[i].firstname+" "+json[i].lastname)
}
}
text()