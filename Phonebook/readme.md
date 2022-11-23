<h1>Телефонный справочник</h1>
<p>Напишите программу «Телефонный справочник».</p>
<p>На вход программе поступают запросы трёх типов:</p>
<p><b>69-70-30 Ivanov</b> — добавить телефон и фамилию абонента в справочник</p>
<p><b>69-70-30</b> — узнать фамилию абонента по номеру телефона</p>
<p><b>Ivanov</b> — узнать телефон абонента по фамилии </p>
<p>Необходимо выводить в консоль ответ на запросы 2 и 3. Обратите внимание, что абоненты по разным номерам могут иметь одинаковые фамилии. В таком случае на запрос 3 необходимо выдать все номера через пробелы. </p>
<p>Операции запросов должны работать за O(logn) или O(logn × количество номеров с этой фамилией).</p>