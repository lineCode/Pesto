#import "../Base.h"
#import "../Window.h"
#import "../Application.h"
#import "../Element.h"

#include <iostream>

int main(int argc, char **argv) {
    for (auto arg = argv; *arg; arg++) {
        printf("%s\n", *arg);
    }

    auto *application = new Pesto::Application;
    Pesto::utils::setupErrorListener();

    // language=HTML
    std::string xml = u8R"(
<style>
root {
    font-family: Roboto;
    border: 5px solid black;
    background-color: #ddd;
    margin-bottom: 5px;
    font-size: 14px;
}

strong {
    display: inline;
    padding-left: 5px;
    padding-right: 5px;
    background: white;
}

span {
    display: inline;
    background: white;
    padding: 5px;
    border: 1px solid gray;
}
</style>
<root style="width: 250px;">
  Hello World Hello World Hello World Hello World Hello World Hello World Hello World Hello World Hello World Hello World
  Hello World Hello World Hello World Hello World Hello World Hello World Hello World Hello World Hello World
</root>
<root style="width: 250px; text-align: right; border: 15px solid black;">
  Right Right Right Right Right Right Right Right Right Right Right Right Right Right Right Right Right Right
  Right Right Right Right Right Right Right Right Right Right Right Right Right Right Right Right Right Right
</root>
<root style="width: 250px;">
  My first line<br/>
  left
  <div style="background: #eee; border-bottom: 1px solid red;">Hi (red bottom)</div>
  Any yet another long line
</root>
<root style="width: 250px; text-align: center;">
  My first line<br/>
  center
  <div id="Hi1" style="background: #eee; border: 2px solid red; color: red;">Hi</div>
  Any yet another long line
</root>
<root style="width: 250px; text-align: right;">
  My first line
  <div></div>
  right
  <div style="background: #eee;">Hi</div>
  Any yet another long line<br/>
  <div style="width: 100px; background: white;">Block element with width</div>
</root>
<root>
   FullwidthblockFullwidthblockFullwidthblockFullwidthblockFullwidthblockFullwidthblockFullwidthblockFullwidthblock
   FullwidthblockFullwidthblockFullwidthblockFullwidthblockFullwidthblockFullwidthblockFullwidthblockFullwidthblockFull
</root>
<root style="width: 250px;">
  Hello <strong>World</strong>, left.
</root>
<root style="width: 250px; text-align: center;">
  Hello <strong>World</strong>, center.
</root>
<root style="width: 250px; text-align: right;">
  Hello <strong>World</strong>, right.
</root>
<root style="width: 250px; text-align: center;">
  Hello <strong style="width: 100px; text-align: left;">World</strong>, center.
</root>
<root style="width: 250px; text-align: center;">
  Hello <strong style="width: 100px;">World</strong>, center.
</root>
<root style="width: 250px; text-align: center;">
  Hello <strong style="width: 100px; text-align: right;">World</strong>, center.
</root>
<root style="width: 50px;">
    Hello.
</root>
<root style="width: 50px;">
    <span style="display: block;">Hello Block</span>
    <span>Hello Span</span> <span>Hello Span</span> <span>Hello Span</span> <span>Hello Span</span> <span>Hello Span</span>
</root>
)";

    auto *window = application->createWindow(xml);
    window->setSize(900, 800);
    window->openDebugger();


    std::cout << window->document->toString();

    printf("Started\n");

    application->loop();

    printf("Done\n");
    return 0;
}