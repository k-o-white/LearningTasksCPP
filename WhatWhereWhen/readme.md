<h1>Реализация игры «Что? Где? Когда?»</h1>
<p>Реализуйте простую версию интеллектуальной игры «Что? Где? Когда?».</p>
<h2>Как происходит игра</h2>
<p>В начале каждого хода игроки вращают волчок, то есть выбирают сектор на столе, который сейчас играет. Всего таких секторов 13. Сектор выбирается так: с клавиатуры вводится офсет (смещение) относительно текущего сектора на барабане. Исходя из этого офсета вычисляется новый активный сектор, который и будет играть в этом ходе. Если выпавший сектор уже играл, выбирает следующий неигравший за ним. В начале всей игры стрелка установлена на первом секторе.</p>
<p>Как только играет какой-то из секторов, с него берётся письмо с вопросом — то есть считывается из файла данного сектора. Вопрос показывается на экране.</p>
<p>После того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит этот ответ с помощью стандартного ввода. То, что он ввёл, сравнивается с ответом, который хранится во втором файле, ассоциированном с активным сектором. Данный файл должен содержать лишь одно слово-ответ.</p>
<p>Если ответ знатока-игрока был правильным, ему начисляется один балл. Если неверен, то балл уходит телезрителям.</p>
<p>Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть баллов. После этого называется победитель и программа заканчивает работу.</p>
