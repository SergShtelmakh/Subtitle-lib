#include <QTest>

#include <src/Time.h>

class SubtitleLibTest : public QObject
{
	Q_OBJECT
private slots:
	void testTime()
	{
		auto defaultTime = sub_util::Time();
		QVERIFY(defaultTime.hour() == 0);
		QVERIFY(defaultTime.minute() == 0);
		QVERIFY(defaultTime.second() == 0);
		QVERIFY(defaultTime.msec() == 0);

		QVERIFY(sub_util::Time(1, 1, 1) == sub_util::Time(1, 1, 1));
		QVERIFY(sub_util::Time(1, 0, 1) < sub_util::Time(1, 1, 1));
	}
};

QTEST_MAIN(SubtitleLibTest)

#include "test_SubtitleLib.moc"
