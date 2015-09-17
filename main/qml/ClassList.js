var index = 0;

function addToModel() {
    if (index < model.count) {
        listmodel.append(model.get(index))
        index = index + 1;
    } else {
        addtimer.stop()
    }
}
