<?php
	include "SchoolPage.php";
	
	class Consulta extends SchoolPage{
		public function printBody() {
			$text = "<body>

			<h2>Tabla de Alumnos</h2>

			<table>
			  <tr>
				<th>Nombre</th>
				<th>Apellido</th>
				<th>Promedio Ponderado</th>
				<th>Carrera</th>
			  </tr>
			  <tr>
				<td>Santiago</td>
				<td>Aparicio</td>
				<td>14.2</td>
				<td>Ciencia de la computacion</td>
			  </tr>
			  <tr>
				<td>Claudia</td>
				<td>Paredes</td>
				<td>14.5</td>
				<td>Ciencia de la computacion</td>
			  </tr>
			  <tr>
				<td>Guido</td>
				<td>Tapia</td>
				<td>18.2</td>
				<td>Ciencia de la computacion</td>
			  </tr>
			  <tr>
				<td>Renzo</td>
				<td>Gonzales</td>
				<td>13.2</td>
				<td>Ciencia de la computacion</td>
			  </tr>
			  <tr>
				<td>Gustavo</td>
				<td>Hokari</td>
				<td>15.7</td>
				<td>Administracion de empresas</td>
			  </tr>
			  <tr>
				<td>Stephanie</td>
				<td>llaiqui</td>
				<td>12.5</td>
				<td>Psicologia</td>
			  </tr>
			</table>

			<h2>Lista de alumnos especificos</h2>

			<h3>Santiago Aparicio</h3>
			<ul>
			  <li>Promedio: 14.2</li>
			  <li> Carrera: Ciencia de la computacion</li>
			</ul>
			<h3>Claudia Paredes</h3>
			<ul>
			  <li>Promedio: 14.5</li>
			  <li> Carrera: Ciencia de la computacion</li>
			</ul>
			<h3>Guido Tapia</h3>
			<ul>
			  <li>Promedio: 18.2</li>
			  <li> Carrera: Ciencia de la computacion</li>
			</ul>
			<h3>Renzo Gonzales</h3>
			<ul>
			  <li>Promedio: 13.2</li>
			  <li> Carrera: Ciencia de la computacion</li>
			</ul>
			<h3>Gustavo Hokari</h3>
			<ul>
			  <li>Promedio: 15.7</li>
			  <li> Carrera: Administracion</li>
			</ul>
			<h3>Stephanie llaiqui</h3>
			<ul>
			  <li>Promedio: 12.5</li>
			  <li> Carrera: Psicologia</li>
			</ul>"

		return $text;
		}
	}
	
	$consulta = new Consulta("Consulta de cursos");
	$consulta->printPage();
	
?>
