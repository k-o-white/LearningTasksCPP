<h1>Реализация программы учёта времени</h1>
<p>Используя функцию получения текущего времени std::time, реализуйте простейший менеджер учёта времени.</p>
<p>Пользователь взаимодействует с программой с помощью команд:</p>
<ul>
  <li>Команда begin начинает отслеживание новой задачи. После ввода этой команды пользователь должен ввести название задачи, над которой он планирует сейчас работать. Если уже была начата какая-то другая задача, предыдущая должна быть автоматически завершена и начата новая.</li>
  <li>Команда end заканчивает отслеживание текущей задачи. Если текущей начатой задачи нет, то команда ничего не делает.</li>
  <li>Команда status выводит на экран информацию о всех законченных задачах и времени, которое было на них потрачено. Также выводится название текущей выполняемой задачи, если таковая имеется.</li>
  <li>Команда exit выходит из программы.</li>
</ul>
