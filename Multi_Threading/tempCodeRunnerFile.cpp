int main()
{
    thread t(run, 11);
    cout << "main" << endl;
    if (t.joinable())
        t.detach();                  //It do not wait thread to complete,
    cout << "main goin end" << endl; //after thread will run before main thread ends(if its fast enough)
    this_thread::sleep_for(chrono::seconds(3));     // Use to see detach behaviour
    return 0;
}