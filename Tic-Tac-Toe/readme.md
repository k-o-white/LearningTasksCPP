<h1>Крестики-нолики</h1>
<h2>Что нужно сделать</h2>

<p>Старая добрая игра на страницах всех школьных тетрадей. Поле размером 3 × 3 представлено в виде двумерного массива с типом элементов char. Участвуют два игрока, они ходят по очереди и ставят в указанные ими в стандартном вводе координаты свой символ — X или O (буквы латинского алфавита). Как только у одного из игроков будет установлено подряд три крестика или три нолика, он побеждает. Если свободных клеток не осталось, а трёх совпадающих элементов не найдено, то объявляется ничья. Для простоты не будем рассматривать диагональные совпадения — только строго вертикальные и строго горизонтальные.</p>
<br>
<p>Изначально всё поле инициализируется символом пробела — ‘ ‘(для обозначения пробела кавычки одинарные и в одну сторону). Это можно сделать сразу при объявлении либо с помощью вложенного цикла. На каждом ходе при занятой клетке или при неверных координатах этой клетки должно быть выведено сообщение, и игрок должен указать координаты клетки повторно. После каждого хода надо выводить в консоль текущее состояние всего игрового поля для наглядности.</p>