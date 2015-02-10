/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Stdlib\Events;

/**
 * This class offers contextual information of a fired event in the EventsManager
 */
class Event
{
    protected _type { set, get };

    protected _source { get };

    protected _data { set, get };

    protected _stopped = false;

    protected _cancelable = true { get };

    /**
     * @param string type
     * @param object source
     * @param mixed data
     * @param boolean cancelable
     */
    public function __construct(string! type, source, data=null, cancelable=true)
    {

        let this->_type = type,
            this->_source = source;

        if data !== null {
            let this->_data = data;
        }

        if cancelable !== true {
            let this->_cancelable = cancelable;
        }
    }

    /**
     * Stops the event preventing propagation
     */
    public function stop()
    {
        if this->_cancelable {
            let this->_stopped = true;
        } else {
            throw new \Exception("Trying to cancel a non-cancelable event");
        }
    }

    /**
     * Check whether the event is currently stopped
     *
     * @return boolean
     */
    public function isStopped() -> boolean
    {
        return this->_stopped;
    }

}
