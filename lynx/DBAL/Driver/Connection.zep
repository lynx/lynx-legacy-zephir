
namespace Lynx\DBAL\Driver;

interface Connection
{
	public function commit();

	public function rollBack();

	public function beginTransaction();

	public function setEventsManager(eventsManager);
}