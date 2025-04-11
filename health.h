<!DOCTYPE html>
<html>
<head>
    <style>
        body {
            font-family: Arial;
        }
        table {
            border: 1px solid black;
        }
        th, td {
            border: 1px solid black;
            padding: 5px;
        }
        button {
            padding: 5px;
            color: black;
        }
    </style>
    <title>Health Track</title>
</head>
<body>
    <h1>Health Track</h1>
    
    <div>
        Height: <input id="myHeight" type="number">
        Weight: <input id="myWeight" type="number">
        Calories Burnt: <input id="myCalories" type="number">
        <button onclick="saveMyData()">Save</button>
    </div>

    <table id="myTable">
        <thead>
            <tr>
                <th>Date</th>
                <th>Height</th>
                <th>Weight</th>
                <th>BMI</th>
                <th>Calories Burnt</th>
            </tr>
        </thead>
        <tbody id="tableBody">
        </tbody>
    </table>

    <script>
        function saveMyData() {
            var height = document.getElementById("myHeight").value;
            var weight = document.getElementById("myWeight").value;
            var calories = document.getElementById("myCalories").value;
            // get data from other module:
            //var height = parseFloat(document.getElementById('height').value);
            //var weight = parseFloat(document.getElementById('weight').value);
            //var bmi = parseFloat(document.getElementById('BMI').textContent.split(" ")[3]);
            //var caloriesBurned = parseFloat(document.getElementById('result').textContent.split(" ")[5]) || 0

            if (!height || !weight || !calories) {
                alert("Put in all numbers!");
                return;
            }

            var bmi = (weight / ((height / 100) * (height / 100))).toFixed(2);
            var today = new Date().toLocaleDateString();
            
            var myData = {
                date: today,
                height: height,
                weight: weight,
                bmi: bmi,
                calories: calories
            };

            var allData = JSON.parse(localStorage.getItem("myHealth")) || [];
            allData.push(myData);
            localStorage.setItem("myHealth", JSON.stringify(allData));

            showMyData();

            document.getElementById("myHeight").value = "";
            document.getElementById("myWeight").value = "";
            document.getElementById("myCalories").value = "";
        }

        function showMyData() {
            var tableBody = document.getElementById("tableBody");
            tableBody.innerHTML = "";

            var allData = JSON.parse(localStorage.getItem("myHealth")) || [];

            for (var data of allData) {
                var row = tableBody.insertRow(0);
                row.innerHTML = `
                    <td>${data.date}</td>
                    <td>${data.height}</td>
                    <td>${data.weight}</td>
                    <td>${data.bmi}</td>
                    <td>${data.calories}</td>
                `;
            }
        }

        window.onload = showMyData;
    </script>
</body>
</html>