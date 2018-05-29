#pragma warning(disable:4996)
#include <iostream>

#include <boost/optional.hpp>
#include <boost/any.hpp>
#include <boost/process.hpp>
#include <boost/filesystem.hpp>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

using tcp = boost::asio::ip::tcp;
namespace http = boost::beast::http;

std::string get_request(const std::string& host, const std::string& target, size_t port = 80)
{
    enum HTTP_VERSION
    {
        _1_0 = 10,
        _1_1 = 11
    };

    boost::asio::io_context ioc;
    tcp::resolver resolver {ioc};
    tcp::socket socket {ioc};

    auto const results = resolver.resolve(host, std::to_string(port));

    boost::asio::connect(socket, results.begin(), results.end());

    http::request<http::string_body> req {http::verb::get, target, HTTP_VERSION::_1_1};
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    http::write(socket, req);
    boost::beast::flat_buffer buffer;
    http::response<http::dynamic_body> res;

    http::read(socket, buffer, res);

    std::stringstream strstr;
    strstr << res;

    boost::system::error_code ec;
    socket.shutdown(tcp::socket::shutdown_both, ec);

    if (ec && ec != boost::system::errc::not_connected)
        throw boost::system::system_error {ec};

    return strstr.str();
}

boost::optional<float> my_div(int a, int b)
{
    if (b == 0)
        return boost::none;

    return boost::make_optional(static_cast<float>(a) / b);
}

void test_optional()
{
    boost::optional<float> r = my_div(10, 5);
    // проверяем, есть ли значение в |r|
    if (r)
    {
        // получаем значение из |r|
        std::cout << *r << std::endl;
    }
    else
    {
        std::cout << "r is none" << std::endl;
    }
    // если |r| содержит значение, то value_or вернет его
    // если |r| не содержит значение, то value_or аргумент
    std::cout << r.value_or(0) << std::endl;


    boost::optional<float> r2 = my_div(10, 0);
    if (r2)
        std::cout << *r2 << std::endl;
    else
        std::cout << "r is none" << std::endl;
    std::cout << r2.value_or(0) << std::endl;
}

void test_process()
{
    // Запускаем калькулятор на Windows
    boost::process::child c("calc.exe");
    // ждем пока не завершится процесс калькулятора
    c.wait();
    auto exit_code = c.exit_code();
    std::cout << exit_code << std::endl;
}


void test_any()
{
    boost::any value;
    // проверяем, есть ли значение
    std::cout << std::boolalpha << value.empty() << std::endl;

    // |value| хранит int
    value = 1;
    std::cout << std::boolalpha << value.empty() << std::endl;
    // получаем из |value| значение типа int
    std::cout << boost::any_cast<int>(value) << std::endl;


    // |value| хранит std::string, int там больше нет
    value = std::string("some string");
    // получаем из |value| значение типа std::string
    std::cout << boost::any_cast<std::string>(value) << std::endl;

    try
    {
        // получаем из |value| значение типа int,
        // но |value| хранит std::string,
        // генерируется исключение boost::bad_any_cast
        std::cout << boost::any_cast<int>(value) << std::endl;
    }
    catch (boost::bad_any_cast& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void test_filesystem()
{
    boost::filesystem::directory_iterator end;
    // текущая директория
    boost::filesystem::path path("./");
    
    // проверяем существует ли файл file_to_delete.txt в директории |path|
    std::cout << std::boolalpha << boost::filesystem::exists(path / "file_to_delete.txt") << std::endl;

    // пробегаемся по всем файлам в директории |path|
    for (auto it = boost::filesystem::directory_iterator(path); it != end; ++it)
    {
        std::cout << it->path().filename() << std::endl;

        if (it->path().filename() == "file_to_delete.txt")
        {
            // удаляем файл
            boost::filesystem::remove(path / it->path());
        }
    }

    std::cout << std::boolalpha << boost::filesystem::exists(path / "file_to_delete.txt") << std::endl;
}

int main()
{
    test_optional();
    
    test_any();
    
    test_filesystem();
    
    test_process();
    
    // open http://qaru.site/questions/1696185/problems-making-a-sync-http-request-through-proxy-using-boost-beast
    std::string response = get_request(
        "qaru.site",
        "/questions/1696185/problems-making-a-sync-http-request-through-proxy-using-boost-beast");

    return 0;
}
